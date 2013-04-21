/**********************************************************************************
 *
 *      machine/cbmipt.c
 *
 *              Input port macros shared by various CBM computers
 *
 *
 *      TO DO:
 *
 *      - investigate C128 input problem with Left Shift / Shift Lock
 *      - investigate superpet different reading of Caps Lock (check machine/pet.c)
 *      - move here lightpen inputs from vc20.c, eventually
 *      - clean up the "SPECIAL" and "CFG" input ports (e.g. there a quite a lot
 *        of settings that are not checked anymore! we have either to implement
 *        the features properly or, if they're hacks, to remove them)
 *
 *********************************************************************************/

#include "emu.h"
#include "machine/cbmipt.h"
#include "machine/c64_neoram.h"


/***************************** Commodore 64 ****************************************
 *
 *  - common_cbm_keyboard: C64 keyboard; used by C16, C65 and C128 as well
 *  - c64_special: input port for the Restore key and the Shift Lock Switch
 *  - c64_controls: joypads, paddles and lightpen; shared with C65, C128
 *          and CBMB
 *
 **********************************************************************************/

/*

C64 Keyboard Layout
-------------------

                                                                           CLR    INST
    <-   1!   2"   3#   4$   5%   6&   7'   8(   9)   0     +    -    ?    HOME   DEL           f 1


    CTRL   Q    W    E    R    T     Y    U    I    O    P    @    *     UP    RESTORE          f 3

RUN   SHIFT
STOP  LOCK   A    S    D    F     G     H    J    K    L   :[   ;]    =      RETURN             f 5

                                                                           CRSR  CRSR
C=    SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT   U/D    L/R           f 7


                                 SPACEBAR


Notes: "C=" is a key with the Commodore logo, "UP" is an arrow pointing up, the "CRSR" keys at the
bottom-right corner are used to move the cursor on screen (Up/Down and Left/Right resp.).
*/


INPUT_PORTS_START( common_cbm_keyboard )
	PORT_START( "ROW0" )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Crsr Down Up") PORT_CODE(KEYCODE_RALT)        PORT_CHAR(UCHAR_MAMEKEY(DOWN)) PORT_CHAR(UCHAR_MAMEKEY(UP))
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F3)                                    PORT_CHAR(UCHAR_MAMEKEY(F5))
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F2)                                    PORT_CHAR(UCHAR_MAMEKEY(F3))
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F1)                                    PORT_CHAR(UCHAR_MAMEKEY(F1))
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F4)                                    PORT_CHAR(UCHAR_MAMEKEY(F7))
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Crsr Right Left") PORT_CODE(KEYCODE_RCONTROL) PORT_CHAR(UCHAR_MAMEKEY(RIGHT)) PORT_CHAR(UCHAR_MAMEKEY(LEFT))
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Return") PORT_CODE(KEYCODE_ENTER)             PORT_CHAR(13)
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("INST DEL") PORT_CODE(KEYCODE_BACKSPACE)       PORT_CHAR(8) PORT_CHAR(UCHAR_MAMEKEY(INSERT))

	PORT_START( "ROW1" )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Shift (Left)") PORT_CODE(KEYCODE_LSHIFT)      PORT_CHAR(UCHAR_SHIFT_1)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_E)         PORT_CHAR('E')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_S)         PORT_CHAR('S')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Z)         PORT_CHAR('Z')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_4)         PORT_CHAR('4') PORT_CHAR('$')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_A)         PORT_CHAR('A')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_W)         PORT_CHAR('W')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3)         PORT_CHAR('3') PORT_CHAR('#')

	PORT_START( "ROW2" )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_X)         PORT_CHAR('X')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_T)         PORT_CHAR('T')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F)         PORT_CHAR('F')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_C)         PORT_CHAR('C')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_6)         PORT_CHAR('6') PORT_CHAR('&')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_D)         PORT_CHAR('D')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_R)         PORT_CHAR('R')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5)         PORT_CHAR('5') PORT_CHAR('%')

	PORT_START( "ROW3" )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_V)         PORT_CHAR('V')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_U)         PORT_CHAR('U')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_H)         PORT_CHAR('H')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_B)         PORT_CHAR('B')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8)         PORT_CHAR('8') PORT_CHAR('(')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_G)         PORT_CHAR('G')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Y)         PORT_CHAR('Y')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7)         PORT_CHAR('7') PORT_CHAR('\'')

	PORT_START( "ROW4" )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_N)         PORT_CHAR('N')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_O)         PORT_CHAR('O')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_K)         PORT_CHAR('K')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_M)         PORT_CHAR('M')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0)         PORT_CHAR('0')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_J)         PORT_CHAR('J')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_I)         PORT_CHAR('I')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9)         PORT_CHAR('9') PORT_CHAR(')')

	PORT_START( "ROW5" )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COMMA)     PORT_CHAR(',') PORT_CHAR('<')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_OPENBRACE) PORT_CHAR('@')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COLON)     PORT_CHAR(':') PORT_CHAR('[')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_STOP)      PORT_CHAR('.') PORT_CHAR('>')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_EQUALS)    PORT_CHAR('-')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_L)         PORT_CHAR('L')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_P)         PORT_CHAR('P')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_MINUS)     PORT_CHAR('+')

	PORT_START( "ROW6" )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SLASH)                             PORT_CHAR('/') PORT_CHAR('?')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x91  Pi") PORT_CODE(KEYCODE_DEL) PORT_CHAR(0x2191) PORT_CHAR(0x03C0)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSLASH)                         PORT_CHAR('=')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Shift (Right)") PORT_CODE(KEYCODE_RSHIFT) PORT_CHAR(UCHAR_SHIFT_1)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("CLR HOME") PORT_CODE(KEYCODE_INSERT)      PORT_CHAR(UCHAR_MAMEKEY(HOME))
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_QUOTE)                             PORT_CHAR(';') PORT_CHAR(']')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_CLOSEBRACE)                        PORT_CHAR('*')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSLASH2)                        PORT_CHAR('\xA3')

	PORT_START( "ROW7" )
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("RUN STOP") PORT_CODE(KEYCODE_HOME)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Q)                                 PORT_CHAR('Q')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("CBM") PORT_CODE(KEYCODE_LALT)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SPACE)                             PORT_CHAR(' ')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2)                                 PORT_CHAR('2') PORT_CHAR('"')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_TAB)                               PORT_CHAR(UCHAR_SHIFT_2)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x90") PORT_CODE(KEYCODE_TILDE)   PORT_CHAR(0x2190)
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1)                                 PORT_CHAR('1') PORT_CHAR('!')
INPUT_PORTS_END


INPUT_PORTS_START( c64_special )
	PORT_START( "SPECIAL" )  /* special keys */
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("RESTORE") PORT_CODE(KEYCODE_PRTSCR)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("SHIFT LOCK") PORT_CODE(KEYCODE_CAPSLOCK) PORT_TOGGLE PORT_CHAR(UCHAR_MAMEKEY(CAPSLOCK))
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNUSED )
INPUT_PORTS_END


INPUT_PORTS_START( c64_controls )
	PORT_START("CTRLSEL")   /* Controller selection */
	PORT_CONFNAME( 0x07, 0x00, "Gameport A" )
	PORT_CONFSETTING( 0x00, DEF_STR( Joystick ) )
	PORT_CONFSETTING( 0x01, "Paddles 1 & 2" )
	PORT_CONFSETTING( 0x02, "Mouse 1351" )
	PORT_CONFSETTING( 0x03, "Mouse (Non Proportional) 1350" )
	PORT_CONFSETTING( 0x04, "Lightpen" )
//  PORT_CONFSETTING( 0x05, "Koala Pad" )
	PORT_CONFSETTING( 0x06, "Lightgun" )
	PORT_CONFSETTING( 0x07, "No Device Connected" )
	PORT_CONFNAME( 0x70, 0x00, "Gameport B" )
	PORT_CONFSETTING( 0x00, DEF_STR( Joystick ) )
	PORT_CONFSETTING( 0x10, "Paddles 3 & 4" )
//  PORT_CONFSETTING( 0x20, "Mouse 1351" )
//  PORT_CONFSETTING( 0x30, "Mouse (Non Proportional) 1350" )
	PORT_CONFSETTING( 0x70, "No Device Connected" )
	PORT_CONFNAME( 0x80, 0x00, "Swap Gameport A and B") PORT_CODE(KEYCODE_F1) PORT_TOGGLE
	PORT_CONFSETTING(   0x00, DEF_STR( No ) )
	PORT_CONFSETTING(   0x80, DEF_STR( Yes ) )

	PORT_START("JOY1_1B")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_PLAYER(1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0xe0, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START("JOY2_1B")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2) PORT_CODE(KEYCODE_HOME) PORT_CODE(JOYCODE_Y_UP_SWITCH) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2) PORT_CODE(KEYCODE_END) PORT_CODE(JOYCODE_Y_DOWN_SWITCH) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2) PORT_CODE(KEYCODE_DEL) PORT_CODE(JOYCODE_X_LEFT_SWITCH) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2) PORT_CODE(KEYCODE_PGDN) PORT_CODE(JOYCODE_X_RIGHT_SWITCH) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_PLAYER(2) PORT_CODE(KEYCODE_INSERT) PORT_CODE(JOYCODE_BUTTON1) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0xe0, IP_ACTIVE_HIGH, IPT_UNUSED )

	/* Mouse Commodore 1350 was basically working as a Joystick */
	PORT_START("JOY1_2B")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(1) PORT_NAME("Mouse 1350 Up") PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x03)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(1) PORT_NAME("Mouse 1350 Down") PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x03)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1) PORT_NAME("Mouse 1350 Left") PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x03)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1) PORT_NAME("Mouse 1350 Right") PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x03)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_PLAYER(1) PORT_NAME("Mouse 1350 Button 1") PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x03)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_PLAYER(1) PORT_NAME("Mouse 1350 Button 2") PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x03)
	PORT_BIT( 0xc0, IP_ACTIVE_HIGH, IPT_UNUSED )

	/* Still to verify how many mices you were able to plug into a c64 */
	/* Only one, for now */
	PORT_START("JOY2_2B")
	PORT_BIT( 0xff, IP_ACTIVE_HIGH, IPT_UNUSED )
/*  PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(2) PORT_CODE(KEYCODE_HOME) PORT_CODE(JOYCODE_Y_UP_SWITCH)
    PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(2) PORT_CODE(KEYCODE_END) PORT_CODE(JOYCODE_Y_DOWN_SWITCH) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x30)
    PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(2) PORT_CODE(KEYCODE_DEL) PORT_CODE(JOYCODE_X_LEFT_SWITCH) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x30)
    PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2) PORT_CODE(KEYCODE_PGDN) PORT_CODE(JOYCODE_X_RIGHT_SWITCH) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x30)
    PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1 ) PORT_PLAYER(2) PORT_CODE(KEYCODE_INSERT) PORT_CODE(JOYCODE_BUTTON1) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x30)
    PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_PLAYER(2) PORT_CODE(KEYCODE_PGUP) PORT_CODE(JOYCODE_BUTTON2) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x30)
    PORT_BIT( 0xc0, IP_ACTIVE_HIGH, IPT_UNUSED )
*/
	PORT_START("PADDLE1")
	PORT_BIT( 0xff, 128, IPT_PADDLE) PORT_SENSITIVITY(30) PORT_KEYDELTA(20) PORT_MINMAX(0,255) PORT_CENTERDELTA(0) PORT_CODE_DEC(KEYCODE_LEFT) PORT_CODE_INC(KEYCODE_RIGHT) PORT_CODE_DEC(JOYCODE_X_LEFT_SWITCH) PORT_CODE_INC(JOYCODE_X_RIGHT_SWITCH) PORT_PLAYER(1) PORT_REVERSE PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x01)

	PORT_START("PADDLE2")
	PORT_BIT( 0xff, 128, IPT_PADDLE) PORT_SENSITIVITY(30) PORT_KEYDELTA(20) PORT_MINMAX(0,255) PORT_CENTERDELTA(0) PORT_CODE_DEC(KEYCODE_DOWN) PORT_CODE_INC(KEYCODE_UP) PORT_CODE_DEC(JOYCODE_Y_UP_SWITCH) PORT_CODE_INC(JOYCODE_Y_DOWN_SWITCH) PORT_PLAYER(2) PORT_REVERSE PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x01)

	PORT_START("PADDLE3")
	PORT_BIT( 0xff, 128, IPT_PADDLE) PORT_SENSITIVITY(30) PORT_KEYDELTA(20) PORT_MINMAX(0,255) PORT_CENTERDELTA(0) PORT_CODE_DEC(KEYCODE_HOME) PORT_CODE_INC(KEYCODE_PGUP) PORT_PLAYER(3) PORT_REVERSE PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x10)

	PORT_START("PADDLE4")
	PORT_BIT( 0xff, 128, IPT_PADDLE) PORT_SENSITIVITY(30) PORT_KEYDELTA(20) PORT_MINMAX(0,255) PORT_CENTERDELTA(0) PORT_CODE_DEC(KEYCODE_END) PORT_CODE_INC(KEYCODE_PGDN) PORT_PLAYER(4) PORT_REVERSE PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x10)

	PORT_START("TRACKX")
	PORT_BIT( 0x7e, 0x00, IPT_TRACKBALL_X) PORT_SENSITIVITY(100) PORT_KEYDELTA(0) PORT_PLAYER(1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x02)

	PORT_START("TRACKY")
	PORT_BIT( 0x7e, 0x00, IPT_TRACKBALL_Y) PORT_SENSITIVITY(100) PORT_KEYDELTA(0) PORT_PLAYER(1) PORT_REVERSE PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x02)

	PORT_START("LIGHTX")
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_X) PORT_NAME("Lightpen X Axis") PORT_CROSSHAIR(X, 1.0, 0.0, 0) PORT_SENSITIVITY(30) PORT_KEYDELTA(20) PORT_PLAYER(1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x04)

	PORT_START("LIGHTY")
	PORT_BIT( 0xff, 0x00, IPT_TRACKBALL_Y) PORT_NAME("Lightpen Y Axis") PORT_CROSSHAIR(Y, 1.0, 0.0, 0) PORT_SENSITIVITY(30) PORT_KEYDELTA(20) PORT_PLAYER(1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x04)

	PORT_START("OTHER")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_BUTTON1) PORT_NAME("Paddle 1 Button") PORT_CODE(KEYCODE_LCONTROL) PORT_CODE(JOYCODE_BUTTON1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x01)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_BUTTON2) PORT_NAME("Paddle 2 Button") PORT_CODE(KEYCODE_LALT) PORT_CODE(JOYCODE_BUTTON2) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x01)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_BUTTON3) PORT_NAME("Paddle 3 Button") PORT_CODE(KEYCODE_INSERT) PORT_CODE(JOYCODE_BUTTON1) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x10)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON4) PORT_NAME("Paddle 4 Button") PORT_CODE(KEYCODE_DEL) PORT_CODE(JOYCODE_BUTTON2) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x10)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_BUTTON1) PORT_NAME("Lightpen Signal") PORT_CODE(KEYCODE_LCONTROL) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x04)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_BUTTON1) PORT_NAME("Mouse Button Left") PORT_CODE(KEYCODE_LCONTROL) PORT_CODE(JOYCODE_BUTTON1) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x02)
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON2) PORT_NAME("Mouse Button Right") PORT_CODE(KEYCODE_LALT) PORT_CODE(JOYCODE_BUTTON2) PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x02)
INPUT_PORTS_END


/***************************** Commodore 16 ****************************************
 *
 *  - C16 shares Keyboard with C64 (only few changes, see c16.c)
 *  - c16_special: input port for the Shift Lock Switch
 *  - c16_controls: control inputs
 *
 **********************************************************************************/

/*

C16 Keyboard Layout
-------------------

                                                                                   INST
     ESC   1!   2"   3#   4$   5%   6&   7'   8(   9)   0^  LEFT RIGHT  UP  DOWN    DEL           f 1

                                                                                  CLEAR
      CTRL   Q    W    E    R    T     Y    U    I    O    P    @    +     -      HOME            f 3

  RUN   SHIFT
  STOP  LOCK   A    S    D    F     G     H    J    K    L   :[   ;]    *      RETURN             f 5


  C=    SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT     ?     =            HELP


                                 SPACEBAR


Notes: "C=" is a key with the Commodore logo, Shift+0 produces an arrow pointing up (''^'' above).

C116 Keyboard Layout
--------------------

           F1/F4      F2/F5     F3/F6    HELP/F7     HOME/CLEAR   DEL/INST


     ESC   1!   2"   3#   4$   5%   6&   7'   8(   9)   0^   +    -     *


   CONTROL   Q    W    E    R    T     Y    U    I    O    P    @   RETURN

  RUN
  STOP    ??    A    S    D    F     G     H    J    K    L   :[   ;]    =


  C=    SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT
                                                                                    UP
                                                                             LEFT       RIGHT
                                 SPACEBAR                                          DOWN


Plus/4 (also 232/264/364 proto)
-----------------------------------

           F1/F4      F2/F5     F3/F6    HELP/F7

                                                                            CLEAR   INST
     ESC   1!   2"   3#   4$   5%   6&   7'   8(   9)   0^   +    -     =    HOME    DEL        ||      @  +  -  =
                                                                                                ||
                                                                                                ||
   CONTROL   Q    W    E    R    T     Y    U    I    O    P    @    ?     *    CONTROL         ||      7  8  9  *
                                                                                                ||
  RUN   SHIFT                                                                                   ||
  STOP  LOCK   A    S    D    F     G     H    J    K    L   :[   ;]    RETURN                  ||      4  5  6  /
                                                                                                ||
                                                                                                ||               E
  C=    SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT                      ||      1  2  3  n
                                                                                UP              ||               t
                                                                          LEFT       RIGHT      ||               e
                                 SPACEBAR                                      DOWN             ||      0  .  :  r

The 19-keys keypad on the left was present only in the 364 prototype (but probably those
keys were simply wired to the lines of regular number keys of the keyboard).

*/

INPUT_PORTS_START( c16_special )
	PORT_START("SPECIAL")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Shift Lock (switch)") PORT_CODE(KEYCODE_CAPSLOCK) PORT_TOGGLE
	PORT_CONFNAME( 0x40, 0x00, "Swap Gameport 1 and 2") PORT_CODE(KEYCODE_F1) PORT_TOGGLE
	PORT_CONFSETTING(   0x00, DEF_STR( No ) )
	PORT_CONFSETTING(   0x40, DEF_STR( Yes ) )
INPUT_PORTS_END


INPUT_PORTS_START( c16_controls )
	PORT_START("CTRLSEL")   /* Controller selection */
	PORT_CONFNAME( 0x01, 0x00, "Gameport 1" )
	PORT_CONFSETTING( 0x00, DEF_STR( Joystick ) )
	PORT_CONFSETTING( 0x01, "No Device Connected" )
	PORT_CONFNAME( 0x10, 0x00, "Gameport 2" )
	PORT_CONFSETTING( 0x00, DEF_STR( Joystick ) )
	PORT_CONFSETTING( 0x10, "No Device Connected" )

	PORT_START("JOY0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP) PORT_NAME("P1 Up") PORT_8WAY PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN) PORT_NAME("P1 Down") PORT_8WAY PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT) PORT_NAME("P1 Left") PORT_8WAY PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT) PORT_NAME("P1 Right") PORT_8WAY PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1) PORT_NAME("P1 Button") PORT_CONDITION("CTRLSEL", 0x0f, EQUALS, 0x00)

	PORT_START("JOY1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_JOYSTICK_UP) PORT_NAME("P2 Up") PORT_CODE(KEYCODE_HOME) PORT_CODE(JOYCODE_Y_UP_SWITCH) PORT_8WAY PORT_PLAYER(2) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN) PORT_NAME("P2 Down") PORT_CODE(KEYCODE_END) PORT_CODE(JOYCODE_Y_DOWN_SWITCH) PORT_8WAY PORT_PLAYER(2) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT) PORT_NAME("P2 Left") PORT_CODE(KEYCODE_DEL) PORT_CODE(JOYCODE_X_LEFT_SWITCH) PORT_8WAY PORT_PLAYER(2) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT) PORT_NAME("P2 Right") PORT_CODE(KEYCODE_PGDN) PORT_CODE(JOYCODE_X_RIGHT_SWITCH) PORT_8WAY PORT_PLAYER(2) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1) PORT_NAME("P2 Button") PORT_CODE(KEYCODE_LALT) PORT_CODE(JOYCODE_BUTTON1) PORT_PLAYER(2) PORT_CONDITION("CTRLSEL", 0xf0, EQUALS, 0x00)
INPUT_PORTS_END


/***************************** Commodore 128 ***************************************
 *
 *  - C128 shares Controls and Keyboard with C64 (+ a keypad, see c128.c)
 *  - c128_special: input port for the Restore key and the Shift Lock,
 *          TV/RGBI and 40/80 columns switches
 *
 **********************************************************************************/

/*

C128 Keyboard Layout
--------------------


                    CAPS                 LINE   40/80    NO
     ESC  TAB  ALT  LOCK           HELP  FEED  DISPLAY SCROLL      UP  DOWN  LEFT  RIGHT          F1  F3  F5  F7

                                                                             CLR    INST
      <-   1!   2"   3#   4$   5%   6&   7'   8(   9)   0     +    -    ?    HOME   DEL           7   8   9   +


   CONTROL   Q    W    E    R    T     Y    U    I    O    P    @    *     UP    RESTORE          4   5   6   -

  RUN   SHIFT                                                                                                 E
  STOP  LOCK   A    S    D    F     G     H    J    K    L   :[   ;]    =      RETURN             1   2   3   n
                                                                                                              t
                                                                             CRSR  CRSR                       e
  C=    SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT   U/D    L/R             0     .   r


                                   SPACEBAR

Notes: "C=" is a key with the Commodore logo, "UP" is an arrow pointing up, the "CRSR" keys at the bottom-right
corner are used to move the cursor on screen (Up/Down and Left/Right resp.).

*/



/***************************** Commodore 65 ****************************************
 *
 *  - C65 shares Keyboard and Inputs with C64 (+ some function keys, see c65.c)
 *  - c65_special: input port for the Restore key and the Shift Lock and DIN
 *          switches
 *
 **********************************************************************************/

/*

C65 Keyboard Layout
-------------------

    RUN                  CAPS    NO
    STOP       ESC  ALT  LOCK  SCROLL    F1   F3   F5   F7        F9    F11   F13   HELP

                                                                             CLR    INST
      <-   1!   2"   3#   4$   5%   6&   7'   8(   9)   0     +    -    ??    HOME   DEL


   TAB       Q    W    E    R    T     Y    U    I    O    P    @    *     UP    RESTORE

        SHIFT
  CTRL  LOCK   A    S    D    F     G     H    J    K    L   :[   ;]    =      RETURN


  C=    SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT   UP


                                   SPACEBAR                           LEFT  DOWN  RIGHT

Notes: "C=" is a key with the Commodore logo, "UP" is an arrow pointing up.

*/
INPUT_PORTS_START( c65_special )
	PORT_START( "SPECIAL" )  /* special keys */
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Restore") PORT_CODE(KEYCODE_PRTSCR)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Shift Lock (switch)") PORT_CODE(KEYCODE_CAPSLOCK) PORT_TOGGLE PORT_CHAR(UCHAR_MAMEKEY(CAPSLOCK))
	PORT_CONFNAME( 0x20, 0x00, "(C65) Caps Lock (switch)") PORT_CODE(KEYCODE_F3)
	PORT_CONFSETTING(   0x00, DEF_STR( Off ) )
	PORT_CONFSETTING(   0x20, DEF_STR( On ) )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_UNUSED )
INPUT_PORTS_END


/***************************** Commodore Pet ***************************************
 *
 *  - pet_keyboard: original keyboard used by PET2001
 *  - pet_business_keyboard: business keyboard is used by the other computers
 *          in pet.c
 *  - pet_special: input port for the Shift Lock Switch
 *  - pet_config: memory and serial port configurations
 *
 **********************************************************************************/

/*

PET Keyboard Layout
-------------------

                                                                                CLR CRSR CRSR INST
  @    !    "    #    $    %    '    &    \    (    )    <-    [    ]          HOME  U/D  L/R  DEL

 RVS
 OFF     Q    W    E    R    T     Y    U    I    O    P    UP   <    >          7    8    9    /

  SHIFT                                                      STOP
  LOCK     A    S    D    F     G     H    J    K    L   :   RUN  RETURN         4    5    6    *


   SHIFT     Z    X    C    V    B     N    M     ,    ;   ?    SHIFT            1    2    3    +


                                 SPACEBAR                                        0    .    -    =


The PET Keypad has 16 keys, making impossible to map it in a satisfactory way to a PC keypad.
Therefore, default settings for these keys in Full Emulation are currently based on the effect
of the key and not on their real position


PET Business Keyboard Layout
----------------------------

                                                                           CRSR  STOP
    <-   1!   2"   3#   4$   5%   6&   7'   8(   9)   0     :*   -=   UP    L/R   RUN           7   8   9

                                                                        CRSR    DEL
    TAB    Q    W    E    R    T     Y    U    I    O    P    [    \    U/D    INST             4   5   6

     SHIFT
ESC   LOCK   A    S    D    F     G     H    J    K    L   ;+    @     ]      RETURN            1   2   3

RVS                                                                                HOME
OFF   SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT   REPEAT   CLR           0     .


                                   SPACEBAR

*/

INPUT_PORTS_START( pet_keyboard )
	PORT_START( "ROW0" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Crsr Right Left") PORT_CODE(KEYCODE_PGDN) PORT_CHAR(UCHAR_MAMEKEY(RIGHT)) PORT_CHAR(UCHAR_MAMEKEY(LEFT))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Home  Clr Screen") PORT_CODE(KEYCODE_HOME) PORT_CHAR(UCHAR_MAMEKEY(HOME))
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x90") PORT_CODE(KEYCODE_MINUS) PORT_CHAR(0x2190)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9)          PORT_CHAR('(')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7)          PORT_CHAR('&')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5)          PORT_CHAR('%')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3)          PORT_CHAR('#')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1)          PORT_CHAR('!')

	PORT_START( "ROW1" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Del  Inst") PORT_CODE(KEYCODE_DEL) PORT_CHAR(8) PORT_CHAR(UCHAR_MAMEKEY(INSERT))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Crsr Down Up") PORT_CODE(KEYCODE_PGUP) PORT_CHAR(UCHAR_MAMEKEY(DOWN)) PORT_CHAR(UCHAR_MAMEKEY(UP))
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0)          PORT_CHAR(')')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8)          PORT_CHAR('\\')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_6)          PORT_CHAR('\'')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_4)          PORT_CHAR('$')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2)          PORT_CHAR('"')

	PORT_START( "ROW2" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9_PAD)      PORT_CHAR('9')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7_PAD)      PORT_CHAR('7')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x91 Pi") PORT_CODE(KEYCODE_OPENBRACE) PORT_CHAR(0x2191) PORT_CHAR(0x03C0)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_O)          PORT_CHAR('O')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_U)          PORT_CHAR('U')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_T)          PORT_CHAR('T')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_E)          PORT_CHAR('E')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Q)          PORT_CHAR('Q')

	PORT_START( "ROW3" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SLASH_PAD)  PORT_CHAR('/')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8_PAD)      PORT_CHAR('8')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_P)          PORT_CHAR('P')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_I)          PORT_CHAR('I')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Y)          PORT_CHAR('Y')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_R)          PORT_CHAR('R')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_W)          PORT_CHAR('W')

	PORT_START( "ROW4" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_6_PAD)      PORT_CHAR('6')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_4_PAD)      PORT_CHAR('4')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_L)          PORT_CHAR('L')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_J)          PORT_CHAR('J')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_G)          PORT_CHAR('G')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_D)          PORT_CHAR('D')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_A)          PORT_CHAR('A')

	PORT_START( "ROW5" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_ASTERISK)   PORT_CHAR('*')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5_PAD)      PORT_CHAR('5')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COLON)      PORT_CHAR(':')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_K)          PORT_CHAR('K')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_H)          PORT_CHAR('H')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F)          PORT_CHAR('F')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_S)          PORT_CHAR('S')

	PORT_START( "ROW6" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3_PAD)      PORT_CHAR('3')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1_PAD)      PORT_CHAR('1')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Return") PORT_CODE(KEYCODE_ENTER) PORT_CHAR(13)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_STOP)       PORT_CHAR(';')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_M)          PORT_CHAR('M')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_B)          PORT_CHAR('B')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_C)          PORT_CHAR('C')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Z)          PORT_CHAR('Z')

	PORT_START( "ROW7" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_PLUS_PAD)   PORT_CHAR('+')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2_PAD)      PORT_CHAR('2')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SLASH)      PORT_CHAR('?')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COMMA)      PORT_CHAR(',')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_N)          PORT_CHAR('N')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_V)          PORT_CHAR('V')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_X)          PORT_CHAR('X')

	PORT_START( "ROW8" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_MINUS_PAD)  PORT_CHAR('-')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0_PAD)      PORT_CHAR('0')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Shift (Right)") PORT_CODE(KEYCODE_RSHIFT) PORT_CHAR(UCHAR_SHIFT_1)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSLASH)  PORT_CHAR('>')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSPACE)  PORT_CHAR(']')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_TILDE)      PORT_CHAR('@')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Shift (Left)") PORT_CODE(KEYCODE_LSHIFT)

	PORT_START( "ROW9" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Keypad =") PORT_CODE(KEYCODE_ENTER_PAD) PORT_CHAR('=')
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_DEL_PAD)    PORT_CHAR('.')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Stop Run") PORT_CODE(KEYCODE_QUOTE)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_CLOSEBRACE) PORT_CHAR('<')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SPACE)      PORT_CHAR(' ')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_EQUALS)     PORT_CHAR('[')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Rvs Off") PORT_CODE(KEYCODE_TAB)
INPUT_PORTS_END


INPUT_PORTS_START( pet_business_keyboard )
	PORT_START( "ROW0" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Crsr Right Left") PORT_CODE(KEYCODE_PGUP) PORT_CHAR(UCHAR_MAMEKEY(RIGHT)) PORT_CHAR(UCHAR_MAMEKEY(LEFT))
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8_PAD)      PORT_CHAR(UCHAR_MAMEKEY(8_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_EQUALS)     PORT_CHAR('-') PORT_CHAR('=')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8)          PORT_CHAR('8') PORT_CHAR('\\')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5)          PORT_CHAR('5') PORT_CHAR('%')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2)          PORT_CHAR('2') PORT_CHAR('"')

	PORT_START( "ROW1" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9_PAD)      PORT_CHAR(UCHAR_MAMEKEY(9_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x91") PORT_CODE(KEYCODE_BACKSPACE) PORT_CHAR(0x2191)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7_PAD)      PORT_CHAR(UCHAR_MAMEKEY(7_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0_PAD)      PORT_CHAR(UCHAR_MAMEKEY(0_PAD))
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7)          PORT_CHAR('7') PORT_CHAR('&')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_4)          PORT_CHAR('4') PORT_CHAR('$')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1)          PORT_CHAR('1') PORT_CHAR('!')

	PORT_START( "ROW2" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5_PAD)      PORT_CHAR(UCHAR_MAMEKEY(5_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COLON)      PORT_CHAR(';') PORT_CHAR('+')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_K)          PORT_CHAR('K')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSLASH)  PORT_CHAR(']')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_H)          PORT_CHAR('H')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F)          PORT_CHAR('F')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_S)          PORT_CHAR('S')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_ESC)        PORT_CHAR(UCHAR_MAMEKEY(ESC))

	PORT_START( "ROW3" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_6_PAD)      PORT_CHAR(UCHAR_MAMEKEY(6_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_QUOTE)      PORT_CHAR('@')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_L)          PORT_CHAR('L')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Return") PORT_CODE(KEYCODE_ENTER) PORT_CHAR(13)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_J)          PORT_CHAR('J')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_G)          PORT_CHAR('G')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_D)          PORT_CHAR('D')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_A)          PORT_CHAR('A')

	PORT_START( "ROW4" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Del  Inst") PORT_CODE(KEYCODE_DEL) PORT_CHAR(8) PORT_CHAR(UCHAR_MAMEKEY(INSERT))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_P)          PORT_CHAR('P')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_I)          PORT_CHAR('I')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_CLOSEBRACE) PORT_CHAR('\\')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Y)          PORT_CHAR('Y')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_R)          PORT_CHAR('R')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_W)          PORT_CHAR('W')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_TAB)        PORT_CHAR('\t')

	PORT_START( "ROW5" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_4_PAD)      PORT_CHAR(UCHAR_MAMEKEY(4_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_OPENBRACE)  PORT_CHAR('[')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_O)          PORT_CHAR('O')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Crsr Down Up") PORT_CODE(KEYCODE_PGDN) PORT_CHAR(UCHAR_MAMEKEY(DOWN)) PORT_CHAR(UCHAR_MAMEKEY(UP))
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_U)          PORT_CHAR('U')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_T)          PORT_CHAR('T')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_E)          PORT_CHAR('E')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Q)          PORT_CHAR('Q')

	PORT_START( "ROW6" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3_PAD)      PORT_CHAR(UCHAR_MAMEKEY(3_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Shift (Right)") PORT_CODE(KEYCODE_RSHIFT) PORT_CHAR(UCHAR_SHIFT_1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_DEL_PAD)    PORT_CHAR(UCHAR_MAMEKEY(DEL_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_STOP)       PORT_CHAR('.') PORT_CHAR('>')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_B)          PORT_CHAR('B')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_C)          PORT_CHAR('C')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Shift (Left)") PORT_CODE(KEYCODE_LSHIFT)

	PORT_START( "ROW7" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2_PAD)      PORT_CHAR(UCHAR_MAMEKEY(2_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Repeat") PORT_CODE(KEYCODE_LALT)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0)          PORT_CHAR('0') PORT_CHAR(')')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COMMA)      PORT_CHAR(',') PORT_CHAR('<')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_N)          PORT_CHAR('N')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_V)          PORT_CHAR('V')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Z)          PORT_CHAR('Z')

	PORT_START( "ROW8" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1_PAD)      PORT_CHAR(UCHAR_MAMEKEY(1_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SLASH)      PORT_CHAR('/') PORT_CHAR('?')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Home  Clr Screen") PORT_CODE(KEYCODE_HOME) PORT_CHAR(UCHAR_MAMEKEY(HOME))
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_M)          PORT_CHAR('M')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SPACE)      PORT_CHAR(' ')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_X)          PORT_CHAR('X')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Rvs Off") PORT_CODE(KEYCODE_INSERT)

	PORT_START( "ROW9" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_MINUS)      PORT_CHAR(':') PORT_CHAR('*')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Stop Run") PORT_CODE(KEYCODE_END)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9)          PORT_CHAR('9') PORT_CHAR('(')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_6)          PORT_CHAR('6') PORT_CHAR('\'')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3)          PORT_CHAR('3') PORT_CHAR('#')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x90") PORT_CODE(KEYCODE_TILDE) PORT_CHAR(0x2190)
INPUT_PORTS_END


INPUT_PORTS_START( pet_special )
	PORT_START( "SPECIAL" )     /* Special keys */
	PORT_CONFNAME( 0x80, 0x00, "Shift Lock (switch)") PORT_CODE(KEYCODE_CAPSLOCK) PORT_TOGGLE
	PORT_CONFSETTING(0x00, DEF_STR( Off ) )
	PORT_CONFSETTING(0x80, DEF_STR( On ) )
INPUT_PORTS_END


INPUT_PORTS_START( pet_config )
	PORT_START("CFG")
	PORT_CONFNAME( 0x180, 0x180, "Memory")
	PORT_CONFSETTING(   0x000, "4 KByte" )
	PORT_CONFSETTING(   0x080, "8 KByte" )
	PORT_CONFSETTING(   0x100, "16 KByte" )
	PORT_CONFSETTING(   0x180, "32 KByte" )
	PORT_BIT( 0x08, 0x00, IPT_UNUSED ) /* no 8096 hardware */
	PORT_BIT( 0x04, 0x00, IPT_UNUSED ) /* no superpet switch */
	PORT_CONFNAME( 0x02, 0x02, "IEEE488 Bus/Dev 8/Floppy Sim")
	PORT_CONFSETTING(   0x00, DEF_STR( No ) )
	PORT_CONFSETTING(   0x02, DEF_STR( Yes ) )
	PORT_CONFNAME( 0x01, 0x00, "IEEE488 Bus/Dev 9/Floppy Sim")
	PORT_CONFSETTING(   0x00, DEF_STR( No ) )
	PORT_CONFSETTING(   0x01, DEF_STR( Yes ) )
INPUT_PORTS_END



/***************************** Commodore CBMB **************************************
 *
 *  - CBMB machines share Controls (in particular Lightpen) with C64
 *  - cbmb_keyboard: Keyboard used by all the models of this series
 *  - cbmb_special: input port for the Shift Lock Switch
 *
 **********************************************************************************/

/*

CBMB Series Keyboard Layout (based on a CBM 610 keyboard)
---------------------------------------------------------

     F1    F2   F3   F4   F5   F6   F7   F8   F9  F10      DOWN  UP  LEFT  RIGHT     HOME/CLEAR   DEL/INST

                                                                            INS
     ESC   1!   2"   3#   4$   5%   6^   7&   8*   9(   0)   -   =+   <-?   DEL          ?   CE    .    /

                                                                         ________
     TAB     Q    W    E    R    T     Y    U    I    O    P    [    ]  | RETURN |       7    8    9    -
                                                                        |__      |
      SHIFT                                                                |     |
      LOCK     A    S    D    F     G     H    J    K    L   ;:   '"   Pi  |     |       4    5    6    +
                                                                           |_____|
                                                                                                        E
        SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT   C=          1    2    3    n
                                                                                                        t
                                                                                                        e
              CTRL               SPACEBAR                                              0      .    00   r


Notes: "C=" is a key with the Commodore logo, Shift+6 produces an arrow pointing up ("^" above).


*/

INPUT_PORTS_START( cbmb_keyboard )
	PORT_START("ROW0")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Stop  Run") PORT_CODE(KEYCODE_DEL)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("RVS Off") PORT_CODE(KEYCODE_HOME)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Graph  Norm") PORT_CODE(KEYCODE_PGUP)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Home  Clr") PORT_CODE(KEYCODE_INSERT) PORT_CHAR(UCHAR_MAMEKEY(HOME))
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_UP)            PORT_CHAR(UCHAR_MAMEKEY(UP))
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_DOWN)          PORT_CHAR(UCHAR_MAMEKEY(DOWN))
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F10)           PORT_CHAR(UCHAR_MAMEKEY(F10))
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F9)            PORT_CHAR(UCHAR_MAMEKEY(F9))

	PORT_START("ROW1")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F8)            PORT_CHAR(UCHAR_MAMEKEY(F8))
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F7)            PORT_CHAR(UCHAR_MAMEKEY(F7))
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F6)            PORT_CHAR(UCHAR_MAMEKEY(F6))
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F5)            PORT_CHAR(UCHAR_MAMEKEY(F5))
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F4)            PORT_CHAR(UCHAR_MAMEKEY(F4))
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F3)            PORT_CHAR(UCHAR_MAMEKEY(F3))
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F2)            PORT_CHAR(UCHAR_MAMEKEY(F2))
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F1)            PORT_CHAR(UCHAR_MAMEKEY(F1))

	PORT_START("ROW2")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_ASTERISK)      PORT_CHAR(UCHAR_MAMEKEY(SLASH_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SLASH_PAD)     PORT_CHAR(UCHAR_MAMEKEY(ASTERISK))
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Keypad CE") PORT_CODE(KEYCODE_NUMLOCK)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Keypad ?") PORT_CODE(KEYCODE_END)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_LEFT)          PORT_CHAR(UCHAR_MAMEKEY(LEFT))
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_EQUALS)        PORT_CHAR('=') PORT_CHAR('+')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0)             PORT_CHAR('0') PORT_CHAR(')')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9)             PORT_CHAR('9') PORT_CHAR('(')

	PORT_START("ROW3")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8)             PORT_CHAR('8') PORT_CHAR('*')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7)             PORT_CHAR('7') PORT_CHAR('&')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5)             PORT_CHAR('5') PORT_CHAR('%')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_4)             PORT_CHAR('4') PORT_CHAR('$')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3)             PORT_CHAR('3') PORT_CHAR('#')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2)             PORT_CHAR('2') PORT_CHAR('@')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1)             PORT_CHAR('1') PORT_CHAR('!')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_ESC)           PORT_CHAR(UCHAR_MAMEKEY(ESC))

	PORT_START("ROW4")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_MINUS_PAD)     PORT_CHAR(UCHAR_MAMEKEY(MINUS_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9_PAD)         PORT_CHAR(UCHAR_MAMEKEY(9_PAD))
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8_PAD)         PORT_CHAR(UCHAR_MAMEKEY(8_PAD))
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7_PAD)         PORT_CHAR(UCHAR_MAMEKEY(7_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_RIGHT)         PORT_CHAR(UCHAR_MAMEKEY(RIGHT))
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x90  \xC2\xA3") PORT_CODE(KEYCODE_TILDE) PORT_CHAR(0x2190) PORT_CHAR('\xA3')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_MINUS)         PORT_CHAR('-')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_O)             PORT_CHAR('o') PORT_CHAR('O')

	PORT_START("ROW5")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_I)             PORT_CHAR('i') PORT_CHAR('I')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_U)             PORT_CHAR('u') PORT_CHAR('U')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("6  \xE2\x86\x91") PORT_CODE(KEYCODE_6) PORT_CHAR('6') PORT_CHAR(0x2191)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_R)             PORT_CHAR('r') PORT_CHAR('R')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_E)             PORT_CHAR('e') PORT_CHAR('E')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_W)             PORT_CHAR('w') PORT_CHAR('W')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Q)             PORT_CHAR('q') PORT_CHAR('Q')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_TAB)           PORT_CHAR('\t')

	PORT_START("ROW6")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_PLUS_PAD)      PORT_CHAR(UCHAR_MAMEKEY(PLUS_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_6_PAD)         PORT_CHAR(UCHAR_MAMEKEY(6_PAD))
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5_PAD)         PORT_CHAR(UCHAR_MAMEKEY(5_PAD))
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_4_PAD)         PORT_CHAR(UCHAR_MAMEKEY(4_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Del  Ins") PORT_CODE(KEYCODE_BACKSPACE)   PORT_CHAR(8) PORT_CHAR(UCHAR_MAMEKEY(INSERT))
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_CLOSEBRACE)    PORT_CHAR(']')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_P)             PORT_CHAR('p') PORT_CHAR('P')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_L)             PORT_CHAR('l') PORT_CHAR('L')

	PORT_START("ROW7")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_K)             PORT_CHAR('k') PORT_CHAR('K')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_J)             PORT_CHAR('j') PORT_CHAR('J')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Y)             PORT_CHAR('y') PORT_CHAR('Y')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_T)             PORT_CHAR('t') PORT_CHAR('T')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_D)             PORT_CHAR('d') PORT_CHAR('D')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_S)             PORT_CHAR('s') PORT_CHAR('S')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_A)             PORT_CHAR('a') PORT_CHAR('A')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNUSED )

	PORT_START("ROW8")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_ENTER_PAD)     PORT_CHAR(UCHAR_MAMEKEY(ENTER_PAD))
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3_PAD)         PORT_CHAR(UCHAR_MAMEKEY(3_PAD))
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2_PAD)         PORT_CHAR(UCHAR_MAMEKEY(2_PAD))
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1_PAD)         PORT_CHAR(UCHAR_MAMEKEY(1_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("CBM") PORT_CODE(KEYCODE_RALT) PORT_CHAR(UCHAR_MAMEKEY(RALT))
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Return") PORT_CODE(KEYCODE_ENTER) PORT_CHAR(13)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_OPENBRACE)     PORT_CHAR('[')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COLON)         PORT_CHAR(';') PORT_CHAR(':')

	PORT_START("ROW9")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COMMA)         PORT_CHAR(',') PORT_CHAR('<')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_M)             PORT_CHAR('m') PORT_CHAR('M')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_H)             PORT_CHAR('h') PORT_CHAR('H')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_G)             PORT_CHAR('g') PORT_CHAR('G')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F)             PORT_CHAR('f') PORT_CHAR('F')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_X)             PORT_CHAR('x') PORT_CHAR('X')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Z)             PORT_CHAR('z') PORT_CHAR('Z')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_LSHIFT) PORT_CODE(KEYCODE_RSHIFT) PORT_CHAR(UCHAR_SHIFT_1)

	PORT_START("ROW10")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Keypad 00") PORT_CODE(KEYCODE_PGDN)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_DEL_PAD)       PORT_CHAR(UCHAR_MAMEKEY(DEL_PAD))
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0_PAD)         PORT_CHAR(UCHAR_MAMEKEY(0_PAD))
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Pi") PORT_CODE(KEYCODE_BACKSLASH) PORT_CHAR(0x03C0)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_QUOTE)         PORT_CHAR('\'') PORT_CHAR('"')
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SLASH)         PORT_CHAR('/') PORT_CHAR('?')

	PORT_START("ROW11")
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_STOP)          PORT_CHAR('.') PORT_CHAR('>')
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SPACE)         PORT_CHAR(' ')
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_N)             PORT_CHAR('n') PORT_CHAR('N')
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_B)             PORT_CHAR('b') PORT_CHAR('B')
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_V)             PORT_CHAR('v') PORT_CHAR('V')
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_C)             PORT_CHAR('c') PORT_CHAR('C')
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNUSED )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_CODE(KEYCODE_LCONTROL) PORT_CHAR(UCHAR_SHIFT_2)
INPUT_PORTS_END


INPUT_PORTS_START( cbmb_special )
	PORT_START("SPECIAL")
	PORT_BIT( 0x200, 0x200, IPT_UNUSED ) /* ntsc */
	PORT_BIT( 0x100, 0x000, IPT_UNUSED ) /* cbm600 */
	PORT_CONFNAME( 0x04, 0x00, "Shift Lock (switch)") PORT_CODE(KEYCODE_CAPSLOCK) PORT_TOGGLE
	PORT_CONFSETTING(   0x00, DEF_STR( Off ) )
	PORT_CONFSETTING(   0x04, DEF_STR( On ) )
INPUT_PORTS_END


	/***************************** Commodore Vic 20 ***********************************
	*
	*  - vic_keyboard: basic Vic 20 keyboard
	*  - vic_special: input port for the Shift Lock Switch
	*  - vic_controls: joypads and paddles
	*  - VIC20 also has 2 lightpen ports, vic_lightpen_6560 & vic_lightpen_6561
	*          currently in vic20.c (they need visible area parameters for centering)
	*
	**********************************************************************************/

/*

VIC20 Keyboard Layout
---------------------

                                                                           CLR    INST
    <-   1!   2"   3#   4$   5%   6&   7'   8(   9)   0     +    -    ?    HOME   DEL           f 1


    CTRL   Q    W    E    R    T     Y    U    I    O    P    @    *     UP    RESTORE          f 3

RUN   SHIFT
STOP  LOCK   A    S    D    F     G     H    J    K    L   :[   ;]    =      RETURN             f 5

                                                                           CRSR  CRSR
C=    SHIFT     Z    X    C    V    B     N    M    ,<   .>   /?   SHIFT   U/D    L/R           f 7


                                 SPACEBAR


Notes: "C=" is a key with the Commodore logo, "UP" is an arrow pointing up, the "CRSR" keys at the
bottom-right corner are used to move the cursor on screen (Up/Down and Left/Right respectively).
Notice that this is exactly the same layout of C64 keyboard.

*/

INPUT_PORTS_START( vic_keyboard )
	PORT_START( "ROW0" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Del  Inst") PORT_CODE(KEYCODE_BACKSPACE) PORT_CHAR(8) PORT_CHAR(UCHAR_MAMEKEY(INSERT))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSLASH2)     PORT_CHAR('\xA3')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_MINUS)          PORT_CHAR('+')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_9)              PORT_CHAR('9') PORT_CHAR(')')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_7)              PORT_CHAR('7') PORT_CHAR('\'')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_5)              PORT_CHAR('5') PORT_CHAR('%')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_3)              PORT_CHAR('3') PORT_CHAR('#')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_1)              PORT_CHAR('1') PORT_CHAR('!')

	PORT_START( "ROW1" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Return") PORT_CODE(KEYCODE_ENTER) PORT_CHAR(13)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_CLOSEBRACE)     PORT_CHAR('*')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_P)              PORT_CHAR('P')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_I)              PORT_CHAR('I')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Y)              PORT_CHAR('Y')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_R)              PORT_CHAR('R')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_W)              PORT_CHAR('W')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x90") PORT_CODE(KEYCODE_TILDE) PORT_CHAR(0x2190)

	PORT_START( "ROW2" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Crsr Right Left") PORT_CODE(KEYCODE_RCONTROL) PORT_CHAR(UCHAR_MAMEKEY(RIGHT)) PORT_CHAR(UCHAR_MAMEKEY(LEFT))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_QUOTE)          PORT_CHAR(';') PORT_CHAR(']')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_L)              PORT_CHAR('L')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_J)              PORT_CHAR('J')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_G)              PORT_CHAR('G')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_D)              PORT_CHAR('D')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_A)              PORT_CHAR('A')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_TAB)            PORT_CHAR(UCHAR_SHIFT_2)

	PORT_START( "ROW3" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Crsr Down Up") PORT_CODE(KEYCODE_RALT) PORT_CHAR(UCHAR_MAMEKEY(DOWN)) PORT_CHAR(UCHAR_MAMEKEY(UP))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SLASH)          PORT_CHAR('/') PORT_CHAR('?')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COMMA)          PORT_CHAR(',') PORT_CHAR('<')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_N)              PORT_CHAR('N')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_V)              PORT_CHAR('V')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_X)              PORT_CHAR('X')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Shift (Left)") PORT_CODE(KEYCODE_LSHIFT)
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Stop Run") PORT_CODE(KEYCODE_HOME)

	PORT_START( "ROW4" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F1)             PORT_CHAR(UCHAR_MAMEKEY(F1)) PORT_CHAR(UCHAR_MAMEKEY(F2))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Shift (Right)") PORT_CODE(KEYCODE_RSHIFT) PORT_CHAR(UCHAR_SHIFT_1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_STOP)           PORT_CHAR('.') PORT_CHAR('>')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_M)              PORT_CHAR('M')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_B)              PORT_CHAR('B')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_C)              PORT_CHAR('C')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Z)              PORT_CHAR('Z')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_SPACE)          PORT_CHAR(' ')

	PORT_START( "ROW5" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F2)             PORT_CHAR(UCHAR_MAMEKEY(F3)) PORT_CHAR(UCHAR_MAMEKEY(F4))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_BACKSLASH)      PORT_CHAR('=')
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_COLON)          PORT_CHAR(':') PORT_CHAR('[')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_K)              PORT_CHAR('K')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_H)              PORT_CHAR('H')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F)              PORT_CHAR('F')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_S)              PORT_CHAR('S')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("CBM") PORT_CODE(KEYCODE_LCONTROL)

	PORT_START( "ROW6" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F3)             PORT_CHAR(UCHAR_MAMEKEY(F5)) PORT_CHAR(UCHAR_MAMEKEY(F6))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("\xE2\x86\x91  Pi") PORT_CODE(KEYCODE_DEL) PORT_CHAR(0x2191) PORT_CHAR(0x03C0)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_OPENBRACE)      PORT_CHAR('@')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_O)              PORT_CHAR('O')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_U)              PORT_CHAR('U')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_T)              PORT_CHAR('T')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_E)              PORT_CHAR('E')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_Q)              PORT_CHAR('Q')

	PORT_START( "ROW7" )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_F4)             PORT_CHAR(UCHAR_MAMEKEY(F7)) PORT_CHAR(UCHAR_MAMEKEY(F8))
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_NAME("Home  Clr") PORT_CODE(KEYCODE_INSERT) PORT_CHAR(UCHAR_MAMEKEY(HOME))
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_EQUALS)         PORT_CHAR('-')
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_0)              PORT_CHAR('0')
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_8)              PORT_CHAR('8') PORT_CHAR('(')
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_6)              PORT_CHAR('6') PORT_CHAR('&')
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_4)              PORT_CHAR('4') PORT_CHAR('$')
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_KEYBOARD ) PORT_CODE(KEYCODE_2)              PORT_CHAR('2') PORT_CHAR('"')
INPUT_PORTS_END


INPUT_PORTS_START( vic_special )
	PORT_START( "SPECIAL" )  /* special keys */
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_KEYBOARD ) PORT_NAME("Restore") PORT_CODE(KEYCODE_PRTSCR)
	PORT_CONFNAME( 0x01, 0x00, "Shift Lock (switch)") PORT_CODE(KEYCODE_CAPSLOCK) PORT_TOGGLE
	PORT_CONFSETTING(   0x00, DEF_STR( Off ) )
	PORT_CONFSETTING(   0x01, DEF_STR( On ) )
INPUT_PORTS_END


SLOT_INTERFACE_START( cbm2_expansion_cards )
	SLOT_INTERFACE("24k", CBM2_24K)
	SLOT_INTERFACE_INTERNAL("standard", CBM2_STD)
	SLOT_INTERFACE_INTERNAL("graphic", CBM2_GRAPHIC)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( cbm_datassette_devices )
	SLOT_INTERFACE("c1530", C1530)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( cbm_iec_devices )
	SLOT_INTERFACE("c1540", C1540)
	SLOT_INTERFACE("c1541", C1541)
	SLOT_INTERFACE("c1541c", C1541C)
	SLOT_INTERFACE("c1541ii", C1541II)
	SLOT_INTERFACE("fsd2", FSD2)
	SLOT_INTERFACE("c1541dd", C1541_DOLPHIN_DOS)
	SLOT_INTERFACE("c1541pd", C1541_PROFESSIONAL_DOS_V1)
	SLOT_INTERFACE("c1541pdc", C1541_PROLOGIC_DOS_CLASSIC)
	SLOT_INTERFACE("c1570", C1570)
	SLOT_INTERFACE("c1571", C1571)
	SLOT_INTERFACE("c1581", C1581)
	SLOT_INTERFACE("cmdhd", CMD_HD)
	SLOT_INTERFACE("fd2000", FD2000)
	SLOT_INTERFACE("fd4000", FD4000)
	SLOT_INTERFACE("interpod", INTERPOD)
	SLOT_INTERFACE("minichief", MINI_CHIEF)
	SLOT_INTERFACE("serialbox", SERIAL_BOX)
	SLOT_INTERFACE("diag264", DIAG264_SERIAL_LOOPBACK)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( sx1541_iec_devices )
	SLOT_INTERFACE("sx1541", SX1541)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( c128dcr_iec_devices )
	SLOT_INTERFACE("c1571", C1571)
	SLOT_INTERFACE("c1571cr", C1571CR)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( c128d81_iec_devices )
	SLOT_INTERFACE("c1563", C1563)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( cbm_ieee488_devices )
	SLOT_INTERFACE("c2040", C2040)
	SLOT_INTERFACE("c3040", C3040)
	SLOT_INTERFACE("c4040", C4040)
	SLOT_INTERFACE("c8050", C8050)
	SLOT_INTERFACE("c8250", C8250)
	SLOT_INTERFACE("c8250lp", C8250LP)
	SLOT_INTERFACE("sfd1001", SFD1001)
	SLOT_INTERFACE("c2031", C2031)
	SLOT_INTERFACE("c8280", C8280)
	SLOT_INTERFACE("d9060", D9060)
	SLOT_INTERFACE("d9090", D9090)
	SLOT_INTERFACE("softbox", SOFTBOX)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( vic20_expansion_cards )
	SLOT_INTERFACE("exp", VIC1010)
	SLOT_INTERFACE("3k", VIC1210)
	SLOT_INTERFACE("8k", VIC1110)
	SLOT_INTERFACE("16k", VIC1111)

	// the following need ROMs from the software list
	SLOT_INTERFACE_INTERNAL("standard", VIC20_STD)
	SLOT_INTERFACE_INTERNAL("ieee488", VIC1112)
	SLOT_INTERFACE_INTERNAL("megacart", VIC20_MEGACART)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( vic20_user_port_cards )
SLOT_INTERFACE_END

SLOT_INTERFACE_START( vic10_expansion_cards )
	// the following need ROMs from the software list
	SLOT_INTERFACE_INTERNAL("standard", VIC10_STD)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( c64_expansion_cards )
	SLOT_INTERFACE("16k", C64_16KB)
	SLOT_INTERFACE("cpm", C64_CPM)
	SLOT_INTERFACE("dqbb", C64_DQBB)
	SLOT_INTERFACE("easyflash", C64_EASYFLASH)
	SLOT_INTERFACE("georam", C64_GEORAM)
	SLOT_INTERFACE("ide64", C64_IDE64)
	SLOT_INTERFACE("neoram", C64_NEORAM)
	SLOT_INTERFACE("reu1700", C64_REU1700)
	SLOT_INTERFACE("reu1750", C64_REU1750)
	SLOT_INTERFACE("reu1764", C64_REU1764)
	SLOT_INTERFACE("sfxse", C64_SFX_SOUND_EXPANDER)
	SLOT_INTERFACE("supercpu", C64_SUPERCPU)

	// the following need ROMs from the software list
	SLOT_INTERFACE_INTERNAL("standard", C64_STD)
	SLOT_INTERFACE_INTERNAL("comal80", C64_COMAL80)
	SLOT_INTERFACE_INTERNAL("c128_comal80", C128_COMAL80)
	SLOT_INTERFACE_INTERNAL("cs64", C64_CURRAH_SPEECH)
	SLOT_INTERFACE_INTERNAL("dela_ep256", C64_DELA_EP256)
	SLOT_INTERFACE_INTERNAL("ep64", C64_DELA_EP64)
	SLOT_INTERFACE_INTERNAL("ep7x8", C64_DELA_EP7X8)
	SLOT_INTERFACE_INTERNAL("dinamic", C64_DINAMIC)
	SLOT_INTERFACE_INTERNAL("easycalcres", C64_EASY_CALC_RESULT)
	SLOT_INTERFACE_INTERNAL("epyxfastload", C64_EPYX_FAST_LOAD)
	SLOT_INTERFACE_INTERNAL("exos", C64_EXOS)
	SLOT_INTERFACE_INTERNAL("fcc", C64_FCC)
	SLOT_INTERFACE_INTERNAL("final", C64_FINAL)
	SLOT_INTERFACE_INTERNAL("final3", C64_FINAL3)
	SLOT_INTERFACE_INTERNAL("fun_play", C64_FUN_PLAY)
	SLOT_INTERFACE_INTERNAL("ieee488", C64_IEEE488)
	SLOT_INTERFACE_INTERNAL("kingsoft", C64_KINGSOFT)
	SLOT_INTERFACE_INTERNAL("mach5", C64_MACH5)
	SLOT_INTERFACE_INTERNAL("magic_desk", C64_MAGIC_DESK)
	SLOT_INTERFACE_INTERNAL("magic_formel", C64_MAGIC_FORMEL)
	SLOT_INTERFACE_INTERNAL("mikroasm", C64_MIKRO_ASSEMBLER)
	SLOT_INTERFACE_INTERNAL("multiscreen", C64_MULTISCREEN)
	SLOT_INTERFACE_INTERNAL("ocean", C64_OCEAN)
	SLOT_INTERFACE_INTERNAL("pagefox", C64_PAGEFOX)
	SLOT_INTERFACE_INTERNAL("prophet64", C64_PROPHET64)
	SLOT_INTERFACE_INTERNAL("ps64", C64_PS64)
	SLOT_INTERFACE_INTERNAL("rex", C64_REX)
	SLOT_INTERFACE_INTERNAL("rex_ep256", C64_REX_EP256)
	SLOT_INTERFACE_INTERNAL("ross", C64_ROSS)
	SLOT_INTERFACE_INTERNAL("silverrock", C64_SILVERROCK)
	SLOT_INTERFACE_INTERNAL("simons_basic", C64_SIMONS_BASIC)
	SLOT_INTERFACE_INTERNAL("stardos", C64_STARDOS)
	SLOT_INTERFACE_INTERNAL("struct_basic", C64_STRUCTURED_BASIC)
	SLOT_INTERFACE_INTERNAL("super_explode", C64_SUPER_EXPLODE)
	SLOT_INTERFACE_INTERNAL("super_games", C64_SUPER_GAMES)
	SLOT_INTERFACE_INTERNAL("sw8k", C64_SW8K)
	SLOT_INTERFACE_INTERNAL("system3", C64_SYSTEM3)
	SLOT_INTERFACE_INTERNAL("tdos", C64_TDOS)
	SLOT_INTERFACE_INTERNAL("vizawrite", C64_VW64)
	SLOT_INTERFACE_INTERNAL("warp_speed", C64_WARP_SPEED)
	SLOT_INTERFACE_INTERNAL("westermann", C64_WESTERMANN)
	SLOT_INTERFACE_INTERNAL("zaxxon", C64_ZAXXON)
	SLOT_INTERFACE_INTERNAL("xl80", C64_XL80)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( c64_user_port_cards )
	SLOT_INTERFACE("4cga", C64_4CGA)
	SLOT_INTERFACE("4dxh", C64_4DXH)
	SLOT_INTERFACE("4ksa", C64_4KSA)
	SLOT_INTERFACE("4tba", C64_4TBA)
	SLOT_INTERFACE("bn1541", C64_BN1541)
	SLOT_INTERFACE("geocable", C64_GEOCABLE)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( plus4_datassette_devices )
	SLOT_INTERFACE("c1531", C1531)
	SLOT_INTERFACE("diag264", DIAG264_CASSETTE_LOOPBACK)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( plus4_expansion_cards )
	SLOT_INTERFACE("c1551", C1551)
	SLOT_INTERFACE("sid", PLUS4_SID)

	// the following need ROMs from the software list
	SLOT_INTERFACE_INTERNAL("standard", PLUS4_STD)
SLOT_INTERFACE_END

SLOT_INTERFACE_START( plus4_user_port_cards )
	SLOT_INTERFACE("diag264", DIAG264_USER_PORT_LOOPBACK)
SLOT_INTERFACE_END
