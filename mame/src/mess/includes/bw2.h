#pragma once

#ifndef __BW2__
#define __BW2__

#include "emu.h"
#include "cpu/z80/z80.h"
#include "formats/bw2_dsk.h"
#include "machine/bw2exp.h"
#include "machine/ctronics.h"
#include "machine/i8251.h"
#include "machine/i8255.h"
#include "machine/pit8253.h"
#include "machine/ram.h"
#include "machine/serial.h"
#include "machine/wd_fdc.h"
#include "video/msm6255.h"
#include "rendlay.h"

#define Z80_TAG         "ic1"
#define I8255A_TAG      "ic4"
#define WD2797_TAG      "ic5"
#define I8253_TAG       "ic6"
#define I8251_TAG       "ic7"
#define MSM6255_TAG     "ic49"
#define CENTRONICS_TAG  "centronics"
#define RS232_TAG       "rs232"
#define SCREEN_TAG      "screen"

class bw2_state : public driver_device
{
public:
	bw2_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag),
			m_maincpu(*this, Z80_TAG),
			m_uart(*this, I8251_TAG),
			m_fdc(*this, WD2797_TAG),
			m_lcdc(*this, MSM6255_TAG),
			m_centronics(*this, CENTRONICS_TAG),
			m_exp(*this, BW2_EXPANSION_SLOT_TAG),
			m_ram(*this, RAM_TAG),
			m_floppy0(*this, WD2797_TAG":0"),
			m_floppy1(*this, WD2797_TAG":1"),
			m_floppy(NULL),
			m_video_ram(*this, "videoram")
	{ }

	required_device<cpu_device> m_maincpu;
	required_device<i8251_device> m_uart;
	required_device<wd2797_t> m_fdc;
	required_device<msm6255_device> m_lcdc;
	required_device<centronics_device> m_centronics;
	required_device<bw2_expansion_slot_device> m_exp;
	required_device<ram_device> m_ram;
	required_device<floppy_connector> m_floppy0;
	required_device<floppy_connector> m_floppy1;
	floppy_image_device *m_floppy;

	virtual void machine_start();

	DECLARE_READ8_MEMBER( read );
	DECLARE_WRITE8_MEMBER( write );

	DECLARE_WRITE8_MEMBER( ppi_pa_w );
	DECLARE_READ8_MEMBER( ppi_pb_r );
	DECLARE_WRITE8_MEMBER( ppi_pc_w );
	DECLARE_READ8_MEMBER( ppi_pc_r );

	DECLARE_WRITE_LINE_MEMBER( pit_out0_w );
	DECLARE_WRITE_LINE_MEMBER( mtron_w );

	void fdc_intrq_w(bool state);
	void fdc_drq_w(bool state);
	DECLARE_FLOPPY_FORMATS( floppy_formats );

	// keyboard state
	UINT8 m_kb;

	// memory state
	UINT8 m_bank;

	// floppy state
	int m_mtron;
	int m_mfdbk;

	// video state
	optional_shared_ptr<UINT8> m_video_ram;
	virtual void palette_init();
};

#endif
