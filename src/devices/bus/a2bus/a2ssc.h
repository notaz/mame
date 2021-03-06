// license:BSD-3-Clause
// copyright-holders:R. Belmont
/*********************************************************************

    a2ssc.h

    Apple II Super Serial Card

*********************************************************************/

#ifndef __A2BUS_SSC__
#define __A2BUS_SSC__

#include "a2bus.h"
#include "machine/mos6551.h"

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

class a2bus_ssc_device:
	public device_t,
	public device_a2bus_card_interface
{
public:
	// construction/destruction
	a2bus_ssc_device(const machine_config &mconfig, std::string tag, device_t *owner, UINT32 clock);
	a2bus_ssc_device(const machine_config &mconfig, device_type type, std::string name, std::string tag, device_t *owner, UINT32 clock, std::string shortname, std::string source);

	// optional information overrides
	virtual machine_config_constructor device_mconfig_additions() const override;
	virtual const rom_entry *device_rom_region() const override;
	virtual ioport_constructor device_input_ports() const override;

	required_ioport m_dsw1, m_dsw2;

	DECLARE_WRITE_LINE_MEMBER( acia_irq_w );

protected:
	virtual void device_start() override;
	virtual void device_reset() override;

	virtual UINT8 read_c0nx(address_space &space, UINT8 offset) override;
	virtual void write_c0nx(address_space &space, UINT8 offset, UINT8 data) override;
	virtual UINT8 read_cnxx(address_space &space, UINT8 offset) override;
	virtual UINT8 read_c800(address_space &space, UINT16 offset) override;

	required_device<mos6551_device> m_acia;

private:
	UINT8 *m_rom;
	bool m_started;
};

// device type definition
extern const device_type A2BUS_SSC;

#endif  /* __A2BUS_SSC__ */
