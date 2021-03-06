
class mcatadv_state : public driver_device
{
public:
	mcatadv_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag) ,
		m_videoram1(*this, "videoram1"),
		m_videoram2(*this, "videoram2"),
		m_scroll1(*this, "scroll1"),
		m_scroll2(*this, "scroll2"),
		m_spriteram(*this, "spriteram"),
		m_vidregs(*this, "vidregs"){ }

	/* memory pointers */
	required_shared_ptr<UINT16> m_videoram1;
	required_shared_ptr<UINT16> m_videoram2;
	required_shared_ptr<UINT16> m_scroll1;
	required_shared_ptr<UINT16> m_scroll2;
	required_shared_ptr<UINT16> m_spriteram;
	UINT16 *     m_spriteram_old;
	required_shared_ptr<UINT16> m_vidregs;
	UINT16 *     m_vidregs_old;
//  UINT16 *     m_paletteram;    // this currently uses generic palette handlers

	/* video-related */
	tilemap_t    *m_tilemap1;
	tilemap_t    *m_tilemap2;
	int m_palette_bank1;
	int m_palette_bank2;

	/* devices */
	cpu_device *m_maincpu;
	cpu_device *m_soundcpu;
	DECLARE_WRITE16_MEMBER(mcat_soundlatch_w);
	DECLARE_WRITE16_MEMBER(mcat_coin_w);
	DECLARE_READ16_MEMBER(mcat_wd_r);
	DECLARE_WRITE8_MEMBER(mcatadv_sound_bw_w);
	DECLARE_WRITE16_MEMBER(mcatadv_videoram1_w);
	DECLARE_WRITE16_MEMBER(mcatadv_videoram2_w);
	TILE_GET_INFO_MEMBER(get_mcatadv_tile_info1);
	TILE_GET_INFO_MEMBER(get_mcatadv_tile_info2);
	virtual void machine_start();
	virtual void video_start();
	UINT32 screen_update_mcatadv(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	void screen_eof_mcatadv(screen_device &screen, bool state);
};
