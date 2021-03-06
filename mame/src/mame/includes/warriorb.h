/*************************************************************************

    Taito Dual Screen Games

*************************************************************************/

class warriorb_state : public driver_device
{
public:
	warriorb_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag) ,
		m_spriteram(*this, "spriteram"){ }

	/* memory pointers */
	required_shared_ptr<UINT16> m_spriteram;

	/* misc */
	INT32      m_banknum;
	int        m_pandata[4];

	/* devices */
	cpu_device *m_maincpu;
	cpu_device *m_audiocpu;
	device_t *m_tc0140syt;
	device_t *m_tc0100scn_1;
	device_t *m_tc0100scn_2;
	device_t *m_lscreen;
	device_t *m_rscreen;
	device_t *m_2610_1l;
	device_t *m_2610_1r;
	device_t *m_2610_2l;
	device_t *m_2610_2r;
	DECLARE_WRITE8_MEMBER(sound_bankswitch_w);
	DECLARE_WRITE16_MEMBER(warriorb_sound_w);
	DECLARE_READ16_MEMBER(warriorb_sound_r);
	DECLARE_WRITE8_MEMBER(warriorb_pancontrol);
	DECLARE_WRITE16_MEMBER(tc0100scn_dual_screen_w);
	virtual void machine_start();
	virtual void machine_reset();
	virtual void video_start();
	UINT32 screen_update_warriorb_left(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	UINT32 screen_update_warriorb_right(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
};
