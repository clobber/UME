/*************************************************************************

    Lethal Enforcers

*************************************************************************/

class lethal_state : public driver_device
{
public:
	lethal_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag) { }

	/* video-related */
	int        m_layer_colorbase[4];
	int        m_sprite_colorbase;

	/* misc */
	UINT8      m_cur_control2;

	/* devices */
	cpu_device *m_maincpu;
	cpu_device *m_audiocpu;
	device_t *m_k054539;
	device_t *m_k056832;
	device_t *m_k053244;
	device_t *m_k054000;
	DECLARE_WRITE8_MEMBER(control2_w);
	DECLARE_WRITE8_MEMBER(sound_cmd_w);
	DECLARE_WRITE8_MEMBER(sound_irq_w);
	DECLARE_READ8_MEMBER(sound_status_r);
	DECLARE_WRITE8_MEMBER(le_bankswitch_w);
	DECLARE_READ8_MEMBER(le_4800_r);
	DECLARE_WRITE8_MEMBER(le_4800_w);
	DECLARE_WRITE8_MEMBER(le_bgcolor_w);
	DECLARE_READ8_MEMBER(guns_r);
	DECLARE_READ8_MEMBER(gunsaux_r);
	DECLARE_WRITE8_MEMBER(lethalen_palette_control);
	DECLARE_DRIVER_INIT(lethalen);
	virtual void machine_start();
	virtual void machine_reset();
	virtual void video_start();
	UINT32 screen_update_lethalen(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	INTERRUPT_GEN_MEMBER(lethalen_interrupt);
};

/*----------- defined in video/lethal.c -----------*/
extern void lethalen_sprite_callback(running_machine &machine, int *code, int *color, int *priority_mask);
extern void lethalen_tile_callback(running_machine &machine, int layer, int *code, int *color, int *flags);
