/*****************************************************************************
 *
 * includes/ps2.h
 *
 ****************************************************************************/

#ifndef PS2_H_
#define PS2_H_


/*----------- defined in machine/ps2.c -----------*/

	DECLARE_READ8_HANDLER(ps2_pos_r);
DECLARE_WRITE8_HANDLER(ps2_pos_w);


#endif /* PS2_H_ */
