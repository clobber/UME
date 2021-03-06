/*****************************************************************************
 *
 * includes/orion.h
 *
 ****************************************************************************/

#ifndef ORION_H_
#define ORION_H_

#include "machine/wd_fdc.h"
#include "includes/radio86.h"
#include "machine/i8255.h"

class orion_state : public radio86_state
{
public:
	orion_state(const machine_config &mconfig, device_type type, const char *tag)
		: radio86_state(mconfig, type, tag),
			m_fdc(*this, "fd1793")
		{ }

	UINT8 m_orion128_video_mode;
	UINT8 m_orion128_video_page;
	UINT8 m_orion128_video_width;
	UINT8 m_video_mode_mask;
	UINT8 m_orionpro_pseudo_color;
	UINT8 m_romdisk_lsb;
	UINT8 m_romdisk_msb;
	UINT8 m_orion128_memory_page;
	UINT8 m_orionz80_memory_page;
	UINT8 m_orionz80_dispatcher;
	UINT8 m_speaker;
	UINT8 m_orionpro_ram0_segment;
	UINT8 m_orionpro_ram1_segment;
	UINT8 m_orionpro_ram2_segment;
	UINT8 m_orionpro_page;
	UINT8 m_orionpro_128_page;
	UINT8 m_orionpro_rom2_segment;
	UINT8 m_orionpro_dispatcher;

	required_device<fd1793_t> m_fdc;

	DECLARE_READ8_MEMBER(orion128_system_r);
	DECLARE_WRITE8_MEMBER(orion128_system_w);
	DECLARE_READ8_MEMBER(orion128_romdisk_r);
	DECLARE_WRITE8_MEMBER(orion128_romdisk_w);
	DECLARE_WRITE8_MEMBER(orion128_video_mode_w);
	DECLARE_WRITE8_MEMBER(orion128_video_page_w);
	DECLARE_WRITE8_MEMBER(orion128_memory_page_w);
	DECLARE_WRITE8_MEMBER(orion_disk_control_w);
	DECLARE_READ8_MEMBER(orion128_floppy_r);
	DECLARE_WRITE8_MEMBER(orion128_floppy_w);
	DECLARE_READ8_MEMBER(orionz80_floppy_rtc_r);
	DECLARE_WRITE8_MEMBER(orionz80_floppy_rtc_w);
	DECLARE_WRITE8_MEMBER(orionz80_sound_w);
	DECLARE_WRITE8_MEMBER(orionz80_sound_fe_w);
	DECLARE_WRITE8_MEMBER(orionz80_memory_page_w);
	DECLARE_WRITE8_MEMBER(orionz80_dispatcher_w);
	DECLARE_READ8_MEMBER(orionz80_io_r);
	DECLARE_WRITE8_MEMBER(orionz80_io_w);
	DECLARE_WRITE8_MEMBER(orionpro_memory_page_w);
	DECLARE_READ8_MEMBER(orionpro_io_r);
	DECLARE_WRITE8_MEMBER(orionpro_io_w);
	DECLARE_MACHINE_START(orion128);
	DECLARE_MACHINE_RESET(orion128);
	DECLARE_VIDEO_START(orion128);
	DECLARE_PALETTE_INIT(orion128);
	DECLARE_MACHINE_START(orionz80);
	DECLARE_MACHINE_RESET(orionz80);
	DECLARE_MACHINE_RESET(orionpro);
	UINT32 screen_update_orion128(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	INTERRUPT_GEN_MEMBER(orionz80_interrupt);
	DECLARE_READ8_MEMBER(orion_romdisk_porta_r);
	DECLARE_WRITE8_MEMBER(orion_romdisk_portb_w);
	DECLARE_WRITE8_MEMBER(orion_romdisk_portc_w);
	DECLARE_FLOPPY_FORMATS( orion_floppy_formats );
};

/*----------- defined in machine/orion.c -----------*/
extern const i8255_interface orion128_ppi8255_interface_1;

#endif /* ORION_H_ */
