class zac2650_state : public driver_device
{
public:
	zac2650_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag) ,
		m_videoram(*this, "videoram"),
		m_s2636_0_ram(*this, "s2636_0_ram"){ }

	required_shared_ptr<UINT8> m_videoram;
	required_shared_ptr<UINT8> m_s2636_0_ram;
	bitmap_ind16 m_bitmap;
	bitmap_ind16 m_spritebitmap;
	int m_CollisionBackground;
	int m_CollisionSprite;
	tilemap_t *m_bg_tilemap;
	DECLARE_WRITE8_MEMBER(tinvader_sound_w);
	DECLARE_WRITE8_MEMBER(tinvader_videoram_w);
	DECLARE_READ8_MEMBER(zac_s2636_r);
	DECLARE_WRITE8_MEMBER(zac_s2636_w);
	DECLARE_READ8_MEMBER(tinvader_port_0_r);
	TILE_GET_INFO_MEMBER(get_bg_tile_info);
	virtual void video_start();
	virtual void palette_init();
	UINT32 screen_update_tinvader(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
};
