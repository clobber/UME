/**********************************************************************

    Coleco Adam Internal 64KB RAM Expansion emulation

    Copyright MESS Team.
    Visit http://mamedev.org for licensing and usage restrictions.

**********************************************************************/

#include "adam_ram.h"



//**************************************************************************
//  DEVICE DEFINITIONS
//**************************************************************************

const device_type ADAM_RAM = &device_creator<adam_ram_expansion_device>;



//**************************************************************************
//  LIVE DEVICE
//**************************************************************************

//-------------------------------------------------
//  adam_ram_expansion_device - constructor
//-------------------------------------------------

adam_ram_expansion_device::adam_ram_expansion_device(const machine_config &mconfig, const char *tag, device_t *owner, UINT32 clock)
	: device_t(mconfig, ADAM_RAM, "Adam 64KB RAM expansion", tag, owner, clock),
		device_adam_expansion_slot_card_interface(mconfig, *this)
{
}


//-------------------------------------------------
//  device_start - device-specific startup
//-------------------------------------------------

void adam_ram_expansion_device::device_start()
{
	adam_ram_pointer(machine(), 64 * 1024);
}


//-------------------------------------------------
//  adam_bd_r - buffered data read
//-------------------------------------------------

UINT8 adam_ram_expansion_device::adam_bd_r(address_space &space, offs_t offset, UINT8 data, int bmreq, int biorq, int aux_rom_cs, int cas1, int cas2)
{
	if (!cas2)
	{
		data = m_ram[offset];
	}

	return data;
}


//-------------------------------------------------
//  adam_bd_w - buffered data write
//-------------------------------------------------

void adam_ram_expansion_device::adam_bd_w(address_space &space, offs_t offset, UINT8 data, int bmreq, int biorq, int aux_rom_cs, int cas1, int cas2)
{
	if (!cas2)
	{
		m_ram[offset] = data;
	}
}
