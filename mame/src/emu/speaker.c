/***************************************************************************

    speaker.c

    Speaker output sound device.

****************************************************************************

    Copyright Aaron Giles
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are
    met:

        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in
          the documentation and/or other materials provided with the
          distribution.
        * Neither the name 'MAME' nor the names of its contributors may be
          used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY AARON GILES ''AS IS'' AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL AARON GILES BE LIABLE FOR ANY DIRECT,
    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
    IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

***************************************************************************/

#include "emu.h"
#include "emuopts.h"
#include "osdepend.h"
#include "config.h"
#include "sound/wavwrite.h"



//**************************************************************************
//  DEBUGGING
//**************************************************************************

#define VERBOSE         (0)

#define VPRINTF(x)      do { if (VERBOSE) mame_printf_debug x; } while (0)



//**************************************************************************
//  GLOBAL VARIABLES
//**************************************************************************

// device type definition
const device_type SPEAKER = &device_creator<speaker_device>;



//**************************************************************************
//  LIVE SPEAKER DEVICE
//**************************************************************************

//-------------------------------------------------
//  speaker_device - constructor
//-------------------------------------------------

speaker_device::speaker_device(const machine_config &mconfig, const char *tag, device_t *owner, UINT32 clock)
	: device_t(mconfig, SPEAKER, "Speaker", tag, owner, clock),
		device_mixer_interface(mconfig, *this),
		m_x(0.0),
		m_y(0.0),
		m_z(0.0)
#ifdef MAME_DEBUG
	,
		m_max_sample(0),
		m_clipped_samples(0),
		m_total_samples(0)
#endif
{
}


//-------------------------------------------------
//  ~speaker_device - destructor
//-------------------------------------------------

speaker_device::~speaker_device()
{
#ifdef MAME_DEBUG
	// log the maximum sample values for all speakers
	if (m_max_sample > 0)
		mame_printf_debug("Speaker \"%s\" - max = %d (gain *= %f) - %d%% samples clipped\n", tag(), m_max_sample, 32767.0 / (m_max_sample ? m_max_sample : 1), (int)((double)m_clipped_samples * 100.0 / m_total_samples));
#endif
}


//-------------------------------------------------
//  static_set_position - configuration helper to
//  set the speaker position
//-------------------------------------------------

void speaker_device::static_set_position(device_t &device, double x, double y, double z)
{
	speaker_device &speaker = downcast<speaker_device &>(device);
	speaker.m_x = x;
	speaker.m_y = y;
	speaker.m_z = z;
}


//-------------------------------------------------
//  mix - mix in samples from the speaker's stream
//-------------------------------------------------

void speaker_device::mix(INT32 *leftmix, INT32 *rightmix, int &samples_this_update, bool suppress)
{
	// skip if no stream
	if (m_mixer_stream == NULL)
		return;

	// update the stream, getting the start/end pointers around the operation
	int numsamples;
	const stream_sample_t *stream_buf = m_mixer_stream->output_since_last_update(0, numsamples);

	// set or assert that all streams have the same count
	if (samples_this_update == 0)
	{
		samples_this_update = numsamples;

		// reset the mixing streams
		memset(leftmix, 0, samples_this_update * sizeof(*leftmix));
		memset(rightmix, 0, samples_this_update * sizeof(*rightmix));
	}
	assert(samples_this_update == numsamples);

#ifdef MAME_DEBUG
	// debug version: keep track of the maximum sample
	for (int sample = 0; sample < samples_this_update; sample++)
	{
		if (stream_buf[sample] > m_max_sample)
			m_max_sample = stream_buf[sample];
		else if (-stream_buf[sample] > m_max_sample)
			m_max_sample = -stream_buf[sample];
		if (stream_buf[sample] > 32767 || stream_buf[sample] < -32768)
			m_clipped_samples++;
		m_total_samples++;
	}
#endif

	// mix if sound is enabled
	if (!suppress)
	{
		// if the speaker is centered, send to both left and right
		if (m_x == 0)
			for (int sample = 0; sample < samples_this_update; sample++)
			{
				leftmix[sample] += stream_buf[sample];
				rightmix[sample] += stream_buf[sample];
			}

		// if the speaker is to the left, send only to the left
		else if (m_x < 0)
			for (int sample = 0; sample < samples_this_update; sample++)
				leftmix[sample] += stream_buf[sample];

		// if the speaker is to the right, send only to the right
		else
			for (int sample = 0; sample < samples_this_update; sample++)
				rightmix[sample] += stream_buf[sample];
	}
}


//-------------------------------------------------
//  device_start - handle device startup
//-------------------------------------------------

void speaker_device::device_start()
{
	// dummy save to make device.c happy
}
