// license:BSD-3-Clause
// copyright-holders:Curt Coder
/**********************************************************************

    COMX-35 Serial/Parallel Printer Card emulation

**********************************************************************/

#pragma once

#ifndef __COMX_PRN__
#define __COMX_PRN__

#include "emu.h"
#include "exp.h"
#include "machine/buffer.h"
#include "bus/centronics/ctronics.h"



//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> comx_prn_device

class comx_prn_device : public device_t,
	public device_comx_expansion_card_interface
{
public:
	// construction/destruction
	comx_prn_device(const machine_config &mconfig, std::string tag, device_t *owner, UINT32 clock);

	// optional information overrides
	virtual const rom_entry *device_rom_region() const override;
	virtual machine_config_constructor device_mconfig_additions() const override;

protected:
	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

	// device_comx_expansion_card_interface overrides
	virtual UINT8 comx_mrd_r(address_space &space, offs_t offset, int *extrom) override;
	virtual UINT8 comx_io_r(address_space &space, offs_t offset) override;
	virtual void comx_io_w(address_space &space, offs_t offset, UINT8 data) override;

private:
	required_device<centronics_device> m_centronics;
	required_device<output_latch_device> m_cent_data_out;
	required_device<input_buffer_device> m_cent_status_in;
	required_memory_region m_rom;
};


// device type definition
extern const device_type COMX_PRN;


#endif
