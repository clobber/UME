/***************************************************************************

    Sigma Spiders hardware

***************************************************************************/
#include "sound/discrete.h"

#define NUM_PENS    (8)

class spiders_state : public driver_device
{
public:
	spiders_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag) ,
		m_ram(*this, "ram"),
		m_discrete(*this, "discrete"){ }

	required_shared_ptr<UINT8> m_ram;
	required_device<discrete_device> m_discrete;
	UINT8 m_flipscreen;
	UINT16 m_gfx_rom_address;
	UINT8 m_gfx_rom_ctrl_mode;
	UINT8 m_gfx_rom_ctrl_latch;
	UINT8 m_gfx_rom_ctrl_data;
	pen_t m_pens[NUM_PENS];
	DECLARE_WRITE_LINE_MEMBER(main_cpu_irq);
	DECLARE_WRITE_LINE_MEMBER(main_cpu_firq);
	DECLARE_WRITE_LINE_MEMBER(audio_cpu_irq);
	DECLARE_WRITE_LINE_MEMBER(flipscreen_w);
	DECLARE_WRITE_LINE_MEMBER(display_enable_changed);
	DECLARE_WRITE8_MEMBER(gfx_rom_intf_w);
	DECLARE_READ8_MEMBER(gfx_rom_r);
	virtual void machine_start();
	INTERRUPT_GEN_MEMBER(update_pia_1);
	DECLARE_WRITE8_MEMBER(ic60_74123_output_changed);
	DECLARE_WRITE8_MEMBER(spiders_audio_command_w);
	DECLARE_WRITE8_MEMBER(spiders_audio_a_w);
	DECLARE_WRITE8_MEMBER(spiders_audio_b_w);
	DECLARE_WRITE8_MEMBER(spiders_audio_ctrl_w);
};

/*----------- defined in audio/spiders.c -----------*/
MACHINE_CONFIG_EXTERN( spiders_audio );
