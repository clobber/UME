/* these are the MPU4 set listings / set specific code, for hardware emulation see mpu4hw.c */

/* todo: driver inits (basic hw reel, protection configs etc.) should probably be moved here
         once the actual code for them is cleaned up and can be put into neater structures
         like bfm_sc4

         due to the vast number of sets here this might be further split up by manufacturer

*/

#include "emu.h"
#include "includes/mpu4.h"

MACHINE_CONFIG_EXTERN( mod4oki );
MACHINE_CONFIG_EXTERN( mod4yam );
MACHINE_CONFIG_EXTERN( mpu4crys );
MACHINE_CONFIG_EXTERN( bwboki );
MACHINE_CONFIG_EXTERN( mod2 );

INPUT_PORTS_EXTERN( mpu4 );
INPUT_PORTS_EXTERN( mpu4jackpot8tkn );
INPUT_PORTS_EXTERN( mpu4jackpot8per );
INPUT_PORTS_EXTERN( grtecp );

ROM_START( m4tst )
	ROM_REGION( 0x10000, "maincpu", ROMREGION_ERASE00  )
	ROM_LOAD( "ut4.p1",  0xC000, 0x4000,  CRC(086dc325) SHA1(923caeb61347ac9d3e6bcec45998ddf04b2c8ffd))
ROM_END

ROM_START( m4tst2 )
	ROM_REGION( 0x10000, "maincpu", ROMREGION_ERASE00  )
	ROM_LOAD( "ut2.p1",  0xE000, 0x2000,  CRC(f7fb6575) SHA1(f7961cbd0801b9561d8cd2d23081043d733e1902))
ROM_END

ROM_START( m4clr )
	ROM_REGION( 0x10000, "maincpu", ROMREGION_ERASE00  )
	ROM_LOAD( "meter-zero.p1",  0x8000, 0x8000,  CRC(e74297e5) SHA1(49a2cc85eda14199975ec37a794b685c839d3ab9))
ROM_END






ROM_START( m4addrd )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dal12.bin", 0x0000, 0x010000, CRC(4affa79a) SHA1(68bceab42b3616641a34a64a83306175ffc1ce32) )
ROM_END







ROM_START( m4amhiwy )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dah20", 0x0000, 0x010000, CRC(e3f92f00) SHA1(122c8a429a1f75dac80b90c4f218bd311813daf5) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "sdr6_1.snd", 0x000000, 0x080000, CRC(63ad952d) SHA1(acc0ac3898fcc281e2d7ba19ada52d727885fe06) )
	ROM_LOAD( "sdr6_2.snd", 0x080000, 0x080000, CRC(48d2ace5) SHA1(ada0180cc60266c0a6d981a019d66bbedbced21a) )
ROM_END









ROM_START( m4blkwhd )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dbw11.bin", 0x0000, 0x010000, CRC(337aaa2c) SHA1(26b12ea3ada9668293c6b44d62458590e5b4ac8f) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "bwsnd.bin", 0x0000, 0x080000, CRC(f247ba83) SHA1(9b173503e63a4a861d1380b2ab1fe14af1a189bd) )
ROM_END



ROM_START( m4blkbul )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cbb08.epr", 0x0000, 0x010000, CRC(09376df6) SHA1(ba3b101accb6bbfbf75b9d22621dbda4efcb7769) )
ROM_END

ROM_START( m4blkcat )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dbl14.bin", 0x0000, 0x010000, CRC(c5db9532) SHA1(309b5122b4a1cb33bbccfb97faf4fa996d29432e) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "dblcsnd.bin", 0x0000, 0x080000, CRC(c90fa8ad) SHA1(a98f03d4b6f5892333279bff7537d4d6d887da62) )

	ROM_REGION( 0x200000, "msm6376_alt", 0 ) // bad dump of some sound rom?
	ROM_LOAD( "sdbl_1.snd", 0x0000, 0x18008e, CRC(e36f71ae) SHA1(ebb643cfa02d28550f2bef135ceefc902baf0df6) )
ROM_END







ROM_START( m4bluedm )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dbd10.bin", 0x0000, 0x010000, CRC(b75e319d) SHA1(8b81e852e318cfde1f5ff2123e1ef7076b208253) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "bdsnd.bin", 0x0000, 0x080000, CRC(8ac4aae6) SHA1(70dba43b398010a8bd0d82cf91553d3f5e0921f0) )
ROM_END




ROM_START( m4brook )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "brkl10.epr", 0x0000, 0x010000, CRC(857255b3) SHA1(cfd77918a19b2532a02b8bb3fa8e2716db31fb0e) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "brkl_snd.epr", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END



ROM_START( m4bucks )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "bufd.p1", 0x0000, 0x010000, CRC(02c575d3) SHA1(92dc7a0c298e4d2d19bf754a5c82cc15e4e6456c) )
	ROM_LOAD( "bufs.p1", 0x0000, 0x010000, CRC(e394ae40) SHA1(911077053c47cebba1bed9d359cd38bd676a46f1) )
ROM_END


ROM_START( m4calicl )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ca2s.p1", 0x0000, 0x010000, CRC(fad153fd) SHA1(bd1f1a5c73624df45d01cb4853d87e998e434d7a) )
	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "ca2s.chr", 0x0000, 0x000048, CRC(97618d38) SHA1(7958e99684d50b9bdb56c97f7fcfe161f0824578) )
ROM_END

ROM_START( m4calicla )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ca2d.p1", 0x0000, 0x010000, CRC(75eb8c6f) SHA1(1bb923d06dcfa24eaf9533c083f68f4bd840834f) )
	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "ca2s.chr", 0x0000, 0x000048, CRC(97618d38) SHA1(7958e99684d50b9bdb56c97f7fcfe161f0824578) )
ROM_END

ROM_START( m4caliclb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ca2f.p1", 0x0000, 0x010000, CRC(6c53cf29) SHA1(2e58453891ab4faa17ef58a81c5f3c0618d046a5) )
	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "ca2s.chr", 0x0000, 0x000048, CRC(97618d38) SHA1(7958e99684d50b9bdb56c97f7fcfe161f0824578) )
ROM_END

ROM_START( m4caliclc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cald.p1", 0x0000, 0x010000, CRC(296fdeeb) SHA1(7782c0c7d8f44e2c0d48cc24c13015241e47b9ec) )
	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "ca2s.chr", 0x0000, 0x000048, CRC(97618d38) SHA1(7958e99684d50b9bdb56c97f7fcfe161f0824578) )
ROM_END

ROM_START( m4calicld )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cals.p1", 0x0000, 0x010000, CRC(28a1c5fe) SHA1(e8474df609ea7f3517780b54d6f493987aad3650) )
	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "ca2s.chr", 0x0000, 0x000048, CRC(97618d38) SHA1(7958e99684d50b9bdb56c97f7fcfe161f0824578) )
ROM_END





ROM_START( m4casmul )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "casinomultiplay.bin", 0x0000, 0x010000, CRC(2ebd1800) SHA1(d15e2593d17d8db9c6946af3366cf429ad291f76) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "casinomultiplaysnd.bin", 0x0000, 0x080000, CRC(be293e95) SHA1(bf0d419c898920a7546b542d8b205e25004ef04f) )
ROM_END

ROM_START( m4oldtmr )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dot11.bin",  0x00000, 0x10000,  CRC(da095666) SHA1(bc7654dc9da1f830a43f925db8079f27e18bb61e))

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "m470.chr", 0x0000, 0x000048, CRC(10d302d4) SHA1(5858e550470a25dcd64efe004c79e6e9783bce07) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "sdot01.bin", 0x0000, 0x080000, CRC(f247ba83) SHA1(9b173503e63a4a861d1380b2ab1fe14af1a189bd) )
ROM_END

ROM_START( m4casot )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "casrom.bin",  0x00000, 0x10000,  CRC(da095666) SHA1(bc7654dc9da1f830a43f925db8079f27e18bb61e) ) // == old timer   (aka b&wrom.bin)

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "caschar.chr", 0x0000, 0x000048, CRC(10d302d4) SHA1(5858e550470a25dcd64efe004c79e6e9783bce07) ) // ( aka b&wchrt.chr )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "cassound.bin", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) ) // ( aka b&wsound.bin )
ROM_END



ROM_START( m4jpmcla )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "jcv2.epr",  0x00000, 0x10000,  CRC(da095666) SHA1(bc7654dc9da1f830a43f925db8079f27e18bb61e) ) // == old timer

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "jcchr.chr", 0x0000, 0x000048, CRC(e370e271) SHA1(2b712dd3590c31356e8b0b62ffc64ff8ce444f73) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "sjcv2.snd", 0x0000, 0x080000, CRC(f247ba83) SHA1(9b173503e63a4a861d1380b2ab1fe14af1a189bd) )
ROM_END


ROM_START( m4ceptr )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dce10.bin", 0x0000, 0x010000, CRC(c94d41ef) SHA1(58fdff2de8dd3ead3980f6f34362183d084ce917) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "cepsnd.p1", 0x000000, 0x080000, CRC(3a91784a) SHA1(7297ccec3264aa9f1e7b3a2841f5f8a1e4ca6c54) )
	ROM_LOAD( "cepsnd.p2", 0x080000, 0x080000, CRC(a82f0096) SHA1(45b6b5a2ae06b45add9cdbb9f5e6f834687b4902) )
ROM_END


#define M4CHASEI_EXTRAS \
	ROM_REGION( 0x48, "fakechr", 0 ) \
	ROM_LOAD( "chaseinvaders.chr", 0x0000, 0x000048, CRC(d7703dcd) SHA1(16fd998d1b44f35c10e5486882aa7f2d018dc82b) ) \
	ROM_REGION( 0x100000, "msm6376", 0 ) \
	ROM_LOAD( "cha.s1", 0x000000, 0x080000, CRC(8200b6bc) SHA1(bcc4ffbddcdcc1dd994fe29e9b24e83272f59442) ) \
	ROM_LOAD( "cha.s2", 0x080000, 0x080000, CRC(542863fa) SHA1(501d66b2badb5036bb5dd8bac3cdb681f630a982) ) \


ROM_START( m4chasei )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ci2c.p1", 0x0000, 0x010000, CRC(fc49a2e1) SHA1(f4f02e168cd9bf0245c2b7340fe151da66f09c5c) )
	M4CHASEI_EXTRAS
ROM_END

ROM_START( m4chaseia )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ch20p8pn.rom", 0x0000, 0x010000, CRC(712bd2e7) SHA1(0e83fa077f42a051aaa07a7e13196955b0ac840d) )
	M4CHASEI_EXTRAS
ROM_END

ROM_START( m4chaseib )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "chin2010l", 0x0000, 0x010000, CRC(7fe97181) SHA1(1ccf65ff108bdaa46efcb3f831fccc953297b9ac) )
	M4CHASEI_EXTRAS
ROM_END

ROM_START( m4chaseic )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ci2k.p1", 0x0000, 0x010000, CRC(8d715b8a) SHA1(5dd6f8d3d6710b0741df37af8792d942f41062d2) )
	M4CHASEI_EXTRAS
ROM_END

ROM_START( m4chaseid )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ci2s.p1", 0x0000, 0x010000, CRC(8175e1e3) SHA1(9a4b0a0288508e7900ceac8bc3b245ac1f898b19) )
	M4CHASEI_EXTRAS
ROM_END

ROM_START( m4chaseie )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ci2y.p1", 0x0000, 0x010000, CRC(80410946) SHA1(60a4f73eb9a35e5c246d8ef7b25bcf25b28bf8ed) )
	M4CHASEI_EXTRAS
ROM_END

ROM_START( m4chaseif )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "chase invaders 8.bin", 0x0000, 0x010000, BAD_DUMP CRC(0bf6a8a0) SHA1(cea5ea40d71484a455615e14f6708b1bc06bbbe8) ) // bad prg (no vectors?)
	M4CHASEI_EXTRAS
ROM_END



ROM_START( m4c9c )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cncs.p1", 0x0000, 0x010000, CRC(10f15e2a) SHA1(c17ab13764d74302246984245485cb7692913b44) )
ROM_END











#define M4CLBVEG_EXTRAS \
	ROM_REGION( 0x48, "fakechr", 0 ) \
	ROM_LOAD( "cvegas.chr", 0x0000, 0x000048, CRC(a6c341b0) SHA1(c8c838c9bb1ced52889504b9cea8d88f1e7fa79f) ) \
	ROM_REGION( 0x100000, "msm6376", 0 ) \
	ROM_LOAD( "cvegass1.hex", 0x0000, 0x080000, CRC(13a8c857) SHA1(c66e10bca1ad54f467b9c5eacd502c54397c09b2) ) \
	ROM_LOAD( "cvegass2.hex", 0x0000, 0x080000, CRC(88b37145) SHA1(1c6c9ad2010e1688d3370d1f2a5ae83dc683b500) ) \


ROM_START( m4clbveg )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "clas.p1", 0x0000, 0x010000, CRC(6aad03f0) SHA1(2f611cc6f020e334dc4b87d2d907727ba15ff7ff) )
	M4CLBVEG_EXTRAS
ROM_END

ROM_START( m4clbvega )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "claf.p1", 0x0000, 0x010000, CRC(79b83184) SHA1(7319a405b2b0b274e03f5cd1465436f8548065e4) )
	M4CLBVEG_EXTRAS
ROM_END

ROM_START( m4clbvegb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "clal.p1", 0x0000, 0x010000, CRC(db0bb5a2) SHA1(2735e02642fb92bb824e3b1f415a1a3ef13a856d) )
	M4CLBVEG_EXTRAS
ROM_END

ROM_START( m4clbvegc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "clad.p1", 0x0000, 0x010000, CRC(4fa45cce) SHA1(58a5d6cc8608eb1aa453429e26eacea589afa524) )
	M4CLBVEG_EXTRAS
ROM_END

#define M4CLBX_EXTRAS \
	ROM_REGION( 0x100000, "msm6376", 0 ) \
	ROM_LOAD( "cxs1.hex", 0x000000, 0x080000, CRC(4ce005f1) SHA1(ee0f59a9c7e0222dd63fa63ccff8f194abd01ddb) ) \
	ROM_LOAD( "cxs2.hex", 0x080000, 0x080000, CRC(495e0730) SHA1(7ba8150fbcf974ac494a82fd373ff02185543e35) ) \


ROM_START( m4clbx )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "clx12s.p1", 0x0000, 0x020000, CRC(6798c153) SHA1(e621e341a0fed1cb35637edb0769ae1cca72a663) )
	M4CLBX_EXTRAS
ROM_END

ROM_START( m4clbxa )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "clx12d.p1", 0x0000, 0x020000, CRC(43e797ba) SHA1(fb2fc843176fe50c1039214d48815d6e9871ae27) )
	M4CLBX_EXTRAS
ROM_END

ROM_START( m4clbxb )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "clx12f.p1", 0x0000, 0x020000, CRC(3e6a82fe) SHA1(01ef9a15a3cf9b1191c573b36fb5758e79c3adc1) )
	M4CLBX_EXTRAS
ROM_END




ROM_START( m4crzjk )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "crjok2.04.bin", 0x0000, 0x010000, CRC(838336d6) SHA1(6f36de20c930cbbff479af2667c11152c6adb43e) )
ROM_END

#define M4CRZJWL_EXTRAS \
	ROM_REGION( 0x180000, "msm6376", 0 ) \
	ROM_LOAD( "cjsound1.bin", 0x000000, 0x080000, CRC(b023f6b9) SHA1(04c362c6511442d3ab775a5ff2051bfe26d5e624) ) \
	ROM_LOAD( "cjsound2.bin", 0x080000, 0x080000, CRC(02563a43) SHA1(dfcee4e0fdf81c726c8e13278e7950459bcaab18) ) \
	ROM_LOAD( "cjsound3.bin", 0x100000, 0x080000, CRC(e722e438) SHA1(070f3772920fa64d5214843c313b27a5b2a4c105) ) \


ROM_START( m4crzjwl )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "cj11bin", 0x0000, 0x020000, CRC(208fda73) SHA1(8b15c197693ea7749bc961fe4e5e36b317f9f6f8) ) // crown jewels (german)
	M4CRZJWL_EXTRAS
ROM_END

ROM_START( m4crzjwla )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "cjexlow", 0x0000, 0x020000, CRC(07c227c1) SHA1(286341ed44ef7cd08ca411f2b3e6936b5e83a5f3) ) // crown jewels (german)
	M4CRZJWL_EXTRAS
ROM_END

ROM_START( m4crzjwlb )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "cjgerman", 0x0000, 0x020000, CRC(b090e690) SHA1(bdbe4041085c995761306280c15f782ea3bdc110) )
	M4CRZJWL_EXTRAS
ROM_END

ROM_START( m4crzjwlc )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "cjj54.bin", 0x0000, 0x020000, CRC(16dc92e7) SHA1(b791535054d5864c7053243408a54accfa014bd1) )
	M4CRZJWL_EXTRAS
ROM_END

ROM_START( m4crzjwld )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "gcn11", 0x0000, 0x020000, CRC(51493500) SHA1(901e60c1a7e9e628d723e199579fc82cf2e433e6) )
	M4CRZJWL_EXTRAS
ROM_END

ROM_START( m4crzjwle )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "gcn111", 0x0000, 0x020000, CRC(b1152ce6) SHA1(1d236bad57ad38b11215efe44008bb8e4014939e) )
	M4CRZJWL_EXTRAS
ROM_END

ROM_START( m4crzjwlf )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "gjv4", 0x0000, 0x020000, CRC(df63105d) SHA1(56e28adef9ec8921da7ab8045859e834731196c5) )
	M4CRZJWL_EXTRAS
ROM_END

ROM_START( m4crzjwlg )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "gjv5", 0x0000, 0x020000, CRC(e4f0bab2) SHA1(1a13d97ff2c4fbae39327f2a5a8b110f2617857e) )
	M4CRZJWL_EXTRAS
ROM_END

ROM_START( m4crzjwlh )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "cjg.p1", 0x0000, 0x020000, CRC(1f4743bf) SHA1(f9a0da2ed9cad5e6685c8a6d1d09e5d4bbcfacec) )    // Crown Jewels Deluxe (german)
	M4CRZJWL_EXTRAS
ROM_END


#define M4CRJWL_EXTRAS \
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 ) \
	/* Missing? or in above set? */ \


ROM_START( m4crjwl )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cjcf.p1", 0x0000, 0x010000, CRC(7feccc74) SHA1(4d1c7c6d2085492ee4205a7383ad7dc1de4e8d60) )
	M4CRJWL_EXTRAS
ROM_END

ROM_START( m4crjwla )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cjcd.p1", 0x0000, 0x010000, CRC(cb83f226) SHA1(f09996436b3db3c8f0fe237884d9125be2b7855e) )
	M4CRJWL_EXTRAS
ROM_END

ROM_START( m4crjwlb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cjcs.p1", 0x0000, 0x010000, CRC(1054e02d) SHA1(067705f20862f6cfc4334c74e0fab1a1016d427c) )
	M4CRJWL_EXTRAS
ROM_END

ROM_START( m4crjwlc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cjn02.p1", 0x0000, 0x010000, CRC(a3d50e20) SHA1(15698e74a37d5f95a5634d48ae2a9a5d19faa2b6) )
	M4CRJWL_EXTRAS
ROM_END

#define M4CRJWL2_EXTRAS \
	ROM_REGION( 0x48, "fakechr", 0 ) \
	ROM_LOAD( "chr.chr", 0x0000, 0x000048, CRC(c5812913) SHA1(d167b1f512c183cf01a1f4e1c1588ea0ae21331b) ) \
	ROM_REGION( 0x100000, "msm6376", 0 ) \
	ROM_LOAD( "cjcs1.hex", 0x000000, 0x080000, CRC(2ac3ba9f) SHA1(3332f29f81918c34aeec3da6f7d001dc9922840d) ) \
	ROM_LOAD( "cjcs2.hex", 0x080000, 0x080000, CRC(89838a9d) SHA1(502243cc0a14e63882b537f05c4cc0eb852e4a0c) ) \


ROM_START( m4crjwl2 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cj214f.p1", 0x0000, 0x010000, CRC(7ee4d30c) SHA1(2bf702bc925c473f7e9eaeb5b3ae0b00e124161a) )
	M4CRJWL2_EXTRAS
ROM_END

ROM_START( m4crjwl2a )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cj214d.p1", 0x0000, 0x010000, CRC(359e2a73) SHA1(c85eeebafca14e6f975953f5daf2772a62693051) )
	M4CRJWL2_EXTRAS
ROM_END

ROM_START( m4crjwl2b )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cj214s.hex", 0x0000, 0x010000, CRC(296aa885) SHA1(045b02848b37e8a04d950d54301dc6888d6178ad) )
	M4CRJWL2_EXTRAS
ROM_END



#define M4DRAC_EXTRAS \
	ROM_REGION( 0x200000, "msm6376", 0 ) \
	ROM_LOAD( "drasnd.p1", 0x000000, 0x080000, CRC(54c3821c) SHA1(1fcc62e2b127dd7f1d5d27a3afdf56dc27f122f8) ) \
	ROM_LOAD( "drasnd.p2", 0x080000, 0x080000, CRC(9096d2bc) SHA1(1b4c530b7b0fde869980d519255e2585c5461e13) ) \
	ROM_LOAD( "drasnd.p3", 0x100000, 0x080000, CRC(a07f412b) SHA1(cca8f5cfe620ece45ca40bf801f0643cd76547e9) ) \
	ROM_LOAD( "drasnd.p4", 0x180000, 0x080000, CRC(018ed789) SHA1(64202da2c542f5ef208faeb04945eb1a758d4746) ) \


ROM_START( m4drac )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "dra21.bin", 0x0000, 0x020000, CRC(23be387e) SHA1(08a78f4b8ddef46069d1c75113300b21e52338c1) )
	M4DRAC_EXTRAS
ROM_END

ROM_START( m4draca )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "dra24.bin", 0x0000, 0x020000, CRC(3db112ae) SHA1(b5303e2a65476931d4769327ca62afd0f6a9eda7) )
	M4DRAC_EXTRAS
ROM_END

ROM_START( m4dracb )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "dra27.p1", 0x0000, 0x020000, CRC(8a095175) SHA1(41006e298f1688499ce6820ec28196c7578684b9) )
	M4DRAC_EXTRAS
ROM_END






ROM_START( m4exgam )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "czep30.bin", 0x0000, 0x010000, CRC(4614e6f6) SHA1(5602a68e9b47394cb31bbcd49a9920e19af6242f) )

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "ceg.chr", 0x0000, 0x000048, CRC(f694224e) SHA1(936ab5e349fa59accbb37959cce9519fd97f3978) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "sczep.bin", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END



#define M4FORTCB_EXTRAS \
	ROM_REGION( 0x100000, "msm6376", 0 ) \
	ROM_LOAD( "cfosnd.p1", 0x000000, 0x080000, CRC(74bbf913) SHA1(52ddc89ab34b11ede2c0e9b9b27e119b0c1eb2d9) ) \
	ROM_LOAD( "cfosnd.p2", 0x080000, 0x080000, CRC(1b2bb79a) SHA1(5f19ea000f34bb404ed6c8ea5ec7b809ccb1ae36) ) \

ROM_START( m4fortcb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cfod.p1", 0x0000, 0x010000, CRC(9d0e2b63) SHA1(cce871d2bbe486793de5de9fadfbddf67c382e5c) )
	M4FORTCB_EXTRAS
ROM_END

ROM_START( m4fortcba )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cfof.p1", 0x0000, 0x010000, CRC(010b3c1f) SHA1(b44c22c21d22603b277138eabf803e6d46ad4aae) )
	M4FORTCB_EXTRAS
ROM_END

ROM_START( m4fortcbb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cfos.p1", 0x0000, 0x010000, CRC(f3b47df4) SHA1(3ad674864ba3a24283af14caaf2c999d4fde11fc) )
	M4FORTCB_EXTRAS
ROM_END






ROM_START( m4frtgm )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "fruit.bin", 0x0000, 0x010000, CRC(dbe44316) SHA1(15cd49dd2e6166f7a7668663f7fea802d6cbb12f) )

	ROM_REGION( 0x800000, "msm6376", 0 ) /* this isn't OKI, or is corrupt (bad size) */
	ROM_LOAD( "fruitsnd.bin", 0x0000, 0x010000, CRC(86547dc7) SHA1(4bf64f22e84c0ee82d961b0ba64932b8bf6a521f) ) // matches 'Replay' on SC1 hardware, probably just belongs there.. or this is eurocoin with different sound hw here?
ROM_END











ROM_START( m4gldgat )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dgg22.bin", 0x0000, 0x010000, CRC(ef8498df) SHA1(6bf164ef18445e83e4510a000bc924cbe916ad99) )

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "m450.chr", 0x0000, 0x000048, CRC(fb7b2a45) SHA1(b6d5537bde9c05a3e79221a5577b8ae77bace9e6) )
ROM_END

ROM_START( m4gldjok )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dgj12.bin", 0x0000, 0x010000, CRC(93ee0c35) SHA1(5ae67b14f7f3d8528fa106519a8a27437c997a70) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "sdgj.snd", 0x0000, 0x080000, CRC(b6cd118b) SHA1(51c5d694ed0dfde8d3fd682f2471d83eec236736) )
ROM_END






ROM_START( m4gnsmk )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dgu16", 0x0000, 0x010000, CRC(6aa23345) SHA1(45e129ec95b1a796f334bedd08469f2ab47a18f8) )

	ROM_REGION( 0x200000, "msm6376", 0 )
	ROM_LOAD( "sdgu01.s1", 0x000000, 0x080000, CRC(bfb284a2) SHA1(860b98d54a3180fbb00b7b03feae049fb4cf9d7f) )
	ROM_LOAD( "sdgu01.s2", 0x080000, 0x080000, CRC(1a46ba28) SHA1(d7154e5f92be8631207620eb313b28990c6a1c7f) )
	ROM_LOAD( "sdgu01.s3", 0x100000, 0x080000, CRC(88bffcf4) SHA1(1da853193f6a22889edff5aafd9440c676a82ea6) )
	ROM_LOAD( "sdgu01.s4", 0x180000, 0x080000, CRC(a6160bef) SHA1(807f7d470728a479a55c782fca3df1eacd0b594c) )
	ROM_END

ROM_START( m4blkbuld )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dgu16", 0x0000, 0x010000, CRC(6aa23345) SHA1(45e129ec95b1a796f334bedd08469f2ab47a18f8) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "dbbsnd.p1", 0x000000, 0x080000, CRC(a913ad0d) SHA1(5f39b661912da903ce8d6658b7848081b191ea56) )
	ROM_LOAD( "dbbsnd.p2", 0x080000, 0x080000, CRC(6a22b39f) SHA1(0e0dbeac4310e03490b665fff514392481ad265f) )
ROM_END


ROM_START( m4hpyjok )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dhj12", 0x0000, 0x010000, CRC(982439d7) SHA1(8d27fcecf7a6a7fd774678580074f945675758f4) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "dhjsnd", 0x0000, 0x080000, CRC(8ac4aae6) SHA1(70dba43b398010a8bd0d82cf91553d3f5e0921f0) )
ROM_END

ROM_START( m4hirise )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "hiix.p1", 0x0000, 0x010000, CRC(c68c816c) SHA1(2ec89d83f3b658700433fc165358290ce58eba64) )
ROM_END

ROM_START( m4hirisea )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "hirs.p1", 0x0000, 0x010000, CRC(a38f771e) SHA1(c1502200671389a1fe6dcb9c043d22583d5991dc) )
ROM_END

ROM_START( m4hiriseb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "hirs20dd", 0x0000, 0x010000, CRC(89941670) SHA1(28859adfa79dce53c348c63b46f6f5a068f2b2de) )
ROM_END

ROM_START( m4hirisec )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "hirx.p1", 0x0000, 0x010000, CRC(4280a16b) SHA1(c9179ec17404a6f084679ad5f04e53a50f00af98) )
ROM_END

ROM_START( m4hirised )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "hirxc.p1", 0x0000, 0x010000, CRC(1ad1d942) SHA1(91d02212606e22b280be9640433e013bc50e5ea8) )
ROM_END

ROM_START( m4hirisee )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "hrise206", 0x0000, 0x010000, CRC(58b4bbdd) SHA1(0b76d27147fbadba97328eb9d2dc81cff9d576e0) )
ROM_END





ROM_START( m4holdtm )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dht10.hex", 0x0000, 0x010000, CRC(217d382b) SHA1(a27dd107c554d4787967633dff998d3962ee0ea5) )

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "ht01.chr", 0x0000, 0x000048, CRC(0fc2bb52) SHA1(0d0e47938f6e00166e7352732ddfb7c610f44db2) )
	ROM_LOAD( "m400.chr", 0x0000, 0x000048, CRC(8f00f720) SHA1(ea59fa2a3b016a7ae83be3caf863de87ce7aeffa) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "sun01.hex", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END






ROM_START( m4jok300 )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "cjo", 0x0000, 0x020000, CRC(386e99db) SHA1(5bb0b513ef63ffaedd98b8e9e7206658fe784fda) )

	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASEFF )
	/* missing? */
ROM_END

ROM_START( m4jokmil )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "cjm03.epr", 0x0000, 0x020000, CRC(e5e4986e) SHA1(149b950a739ad308f7759927c344de8193ce67c5) )

	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASEFF )
	/* missing? */
ROM_END







ROM_START( m4joljokh )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "jollyjokerhungarian.bin", 0x0000, 0x010000, CRC(85b6a406) SHA1(e277f9d3b62faead04d65efbc06de7f4a50ae38d) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "jollyjokerhungariansnd.bin", 0x0000, 0x080000, CRC(93460383) SHA1(2b179a1dde09ebdfe8c84641899df7be87d443e5) )
ROM_END









ROM_START( m4lineup )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lineup5p1.bin", 0xc000, 0x004000, CRC(9ba9edbd) SHA1(385e01816b5631b6896e85343ae96b3c36f9647a) )
	ROM_LOAD( "lineup5p2.bin", 0x8000, 0x004000, CRC(e9e4dfb0) SHA1(46a0efa84770036366c7a6a33ef1d42c7b2b782b) )
	ROM_LOAD( "lineup5p3.bin", 0x6000, 0x002000, CRC(86623376) SHA1(e29442bfcd401361287852b87673368322e946b5) )
ROM_END

ROM_START( m4lineupa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lu2_10p1.bin", 0x0000, 0x004000, CRC(2fb89062) SHA1(55e86de8fd0d36cca9aab8ad5aae7b4f5a62b940) )
	ROM_LOAD( "lu2_10p2.bin", 0x0000, 0x004000, CRC(9d820af2) SHA1(63d27df91f80e47eb8c9685fcd2c3eff902a2ef8) )
	ROM_LOAD( "lu2_10p3.bin", 0x0000, 0x002000, CRC(8c8a210c) SHA1(2599d979f1a62e9ef6acc70d0ad5c9b4a65d712a) )
ROM_END


ROM_START( m4luck7 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dl716.bin", 0x0000, 0x010000, CRC(141b23a9) SHA1(3bfb82ea0ee4104bd8739b545aba617f84bef770) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "dl7snd.bin", 0x0000, 0x080000, CRC(c90fa8ad) SHA1(a98f03d4b6f5892333279bff7537d4d6d887da62) )
ROM_END

ROM_START( m4luckdv )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cld_16.bin", 0x0000, 0x010000, CRC(89f63938) SHA1(8d3a5628e2c0bf39784afe2f00a007d40ea35423) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "cld_snd1.snd", 0x000000, 0x080000, CRC(f247ba83) SHA1(9b173503e63a4a861d1380b2ab1fe14af1a189bd) )
	ROM_LOAD( "cld_snd2.snd", 0x080000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END

ROM_START( m4luckdvd )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dld13", 0x0000, 0x010000, CRC(b8ceb29b) SHA1(84b6ebad300214610635fb8141d18de2b7065435) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "sdld01.snd", 0x000000, 0x080000, CRC(9b035fa6) SHA1(51b7e5bc3abdf4f1beba2347146a91a2b3f4de35) )
ROM_END


#define M4LUCKWB_EXTRAS \
	ROM_REGION( 0x100000, "msm6376", 0 ) /* these are all different sound roms... */  \
	ROM_LOAD( "lwbs3.bin", 0x0000, 0x07dc89, CRC(ee102376) SHA1(3fed581a4654acf285dd430fbfbac33cd67411b8) ) \
	ROM_LOAD( "lwbs7.bin", 0x0000, 0x080000, CRC(5d4177c7) SHA1(e13f145885bb719b0021ae4ce289261a3eaa2e18) ) \
	ROM_LOAD( "lwbs8.bin", 0x0000, 0x080000, CRC(187cdf5b) SHA1(87ec189af27c95f278a7531ec13df53a08889af8) ) \
	ROM_LOAD( "lwbs9.bin", 0x0000, 0x080000, CRC(2e02b617) SHA1(2502a1d2cff155a7fc5148e23a4723d4d60e9d42) ) \


ROM_START( m4luckwb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lwb10.bin", 0x0000, 0x010000, CRC(6d43a14e) SHA1(267aba1a01bfd5f0eaa7683d041d5fcb2d301934) )
	M4LUCKWB_EXTRAS
ROM_END

ROM_START( m4luckwba )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lwb15.bin", 0x0000, 0x010000, CRC(b5af8cb2) SHA1(474975b83803627ad3ac4217d8cecb2d2db16fec) )
	M4LUCKWB_EXTRAS
ROM_END

ROM_START( m4luckwbb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lwb21.bin", 0x0000, 0x010000, CRC(6c570733) SHA1(7488318ca9689371e4f80be0a0fddd8ad141733e) )
	M4LUCKWB_EXTRAS
ROM_END

ROM_START( m4luckwbc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lwb22.bin", 0x0000, 0x010000, CRC(05b952a7) SHA1(952e328b280a18c1ffe253b6a56f2b5e893b1b72) )
	M4LUCKWB_EXTRAS
ROM_END

ROM_START( m4luckwbd )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lwb27.bin", 0x0000, 0x010000, CRC(9d6b6637) SHA1(65bad12cd08de128ca31c9488e32e3cebfb8eedb) )
	M4LUCKWB_EXTRAS
ROM_END

ROM_START( m4luckwbe )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lwb6.bin", 0x0000, 0x010000, CRC(8e7d4594) SHA1(4824a9a4628585a170c41e00f7b3fcb8a2330c02) )
	M4LUCKWB_EXTRAS
ROM_END

ROM_START( m4luckwbf )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "lwb7.bin", 0x0000, 0x010000, CRC(8e651705) SHA1(bd4d09d586d14759a17d4d7d4016c427f3eef015) )
	M4LUCKWB_EXTRAS
ROM_END




ROM_START( m4magdrg )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dmd10.bin", 0x0000, 0x010000, CRC(9cc4f2f8) SHA1(46a90ffa18d35ad2b06542f91120c02bc34f0c40) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "mdsnd.bin", 0x000000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END

ROM_START( m4maglin )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dma21.bin", 0x0000, 0x010000, CRC(836a25e6) SHA1(5f83bb8a2c77dd3b02724c076d6b37d2c1c93b93) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "mlsound1.p1", 0x000000, 0x080000, CRC(ff8749ff) SHA1(509b53f09cdfe5ee865e60ab42fd578586ac53ea) )
	ROM_LOAD( "mlsound2.p2", 0x080000, 0x080000, CRC(c8165b6c) SHA1(7c5059ee8630da31fc3ad50d84a4730297757d46) )
ROM_END

ROM_START( m4magrep )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dmr13.bin", 0x0000, 0x010000, CRC(c3015da3) SHA1(23cd505eedf666c012e4064a5fcf5a983f098e83) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "mrdsound.bin", 0x000000, 0x080000, CRC(9b035fa6) SHA1(51b7e5bc3abdf4f1beba2347146a91a2b3f4de35) )
ROM_END











ROM_START( m4nspot )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ns2s.p1", 0x0000, 0x010000, CRC(ba0f5a81) SHA1(7015176d4528636cb8a753249c824c37941e8eae) )
ROM_END

ROM_START( m4nspota )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ns2d.p1", 0x0000, 0x010000, CRC(5e66b7e0) SHA1(e82044e3c1e5cf3a2baf1fde7b7ab8b6e221d360) )
ROM_END

ROM_START( m4nspotb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "nits.p1", 0x0000, 0x010000, CRC(47c965e6) SHA1(41a337a9a367c4e704a60e32d56b262d03f97b59) )
ROM_END

ROM_START( m4nile )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "gjn08.p1", 0x0000, 0x020000, CRC(2bafac0c) SHA1(363d08f798b5bea409510b1a9415098a69f19ee0) )

	ROM_REGION( 0x200000, "msm6376", 0 )
	ROM_LOAD( "gjnsnd.p1", 0x000000, 0x080000, CRC(1d839591) SHA1(2e4ba74f96e7c0592b85409a3f50ec81e00e064c) )
	ROM_LOAD( "gjnsnd.p2", 0x080000, 0x080000, CRC(e2829c42) SHA1(2139c1625ad163cce99a522c2cf02ee47a8f9007) )
	ROM_LOAD( "gjnsnd.p3", 0x100000, 0x080000, CRC(db084eb4) SHA1(9b46a3cb16974942b0edd25b1b080d30fc60c3df) )
	ROM_LOAD( "gjnsnd.p4", 0x180000, 0x080000, CRC(da785b0a) SHA1(63358ab197eb1de8e489a9fd6ffbc2039efc9536) )
ROM_END




ROM_START( m4nudshf )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "nusx.p1", 0x0000, 0x010000, CRC(87caab84) SHA1(e2492ad0d25ded4d760c4cbe05e9b51ca1a10544) )
ROM_END

ROM_START( m4nudshfa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "nus6", 0x0000, 0x010000, CRC(017c5354) SHA1(07491e4b03ab62ad923f8479300c1af4633e3e8c) )
ROM_END

ROM_START( m4nudshfb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "nuss.bin", 0x0000, 0x010000, CRC(d3b860ee) SHA1(d5d1262c715e4684748b0cae708eeed31b1dc50f) )
ROM_END

ROM_START( m4nudshfc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "nusxc.p1", 0x0000, 0x010000, CRC(e2557b45) SHA1(a9d1514d4fe3897f6fcef22a5039d6bdff8126ff) )
ROM_END



ROM_START( m4ordmnd )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "rab01.p1", 0x0000, 0x020000, CRC(99964fe7) SHA1(3745d09e7a4f417c8e85270d3ffec3e37ee1344d) )

	ROM_REGION( 0x200000, "msm6376", 0 )
	ROM_LOAD( "odsnd1.bin", 0x000000, 0x080000, CRC(d746bae4) SHA1(293e1dc9edf88a183cc23dbb4576cefbc8f9d028) )
	ROM_LOAD( "odsnd2.bin", 0x080000, 0x080000, CRC(84ace1f4) SHA1(9cc70e59e9d26006870ea1cc522de33e71b71692) )
	ROM_LOAD( "odsnd3.bin", 0x100000, 0x080000, CRC(b1b12def) SHA1(d8debf8cfb3af2157d5d1571927588dc1c8d07b6) )
ROM_END


ROM_START( m4ptblkc )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "potblackcasinoprg.bin", 0x0000, 0x020000, CRC(29190084) SHA1(c7a778331369c0fac796ef3e306e12c98605f365) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "potblackcasinosnd.p1", 0x000000, 0x080000, CRC(72a3331d) SHA1(b7475ba0ad86a6277e3d4f7b4311a98f3fc29802) )
	ROM_LOAD( "potblackcasinosnd.p2", 0x080000, 0x080000, CRC(c2460eec) SHA1(7c62fbc69ffaa788bf3839e37a75a812a7b8caef) )
ROM_END





ROM_START( m4prem )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dpm14.bin", 0x0000, 0x010000, CRC(de344759) SHA1(d3e7514da83bbf1eba63661fb0675a6230af93cd) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "dpms.bin", 0x0000, 0x080000, CRC(93fd4253) SHA1(69feda7ffc56defd515c9cd1ce204af3d9731a3f) )
ROM_END



















ROM_START( m4rdht )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "drh12", 0x0000, 0x010000, CRC(b26cd308) SHA1(4e29f6cce773232a1c43cd2fb3ce9b844c446bb8) ) // aka gdjb

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "drh_1.snd", 0x0000, 0x080000, CRC(f652cd0c) SHA1(9ce986bc12bcf22a57e065329e82671d19cc96d7) ) // aka gn.snd
ROM_END







ROM_START( m4rwb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "drw14.bin", 0x0000, 0x010000, CRC(22c30ebe) SHA1(479f66732aac56dae60c80d11f05c084865f9389) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "rwb_1.snd", 0x000000, 0x080000, CRC(e0a6def5) SHA1(e3867b83e588fd6a9039b8d45186480a9d0433ea) )
	ROM_LOAD( "rwb_2.snd", 0x080000, 0x080000, CRC(54a2b2fd) SHA1(25875ff873bf22df510e7a4c56c336fbabcbdedb) )
ROM_END






ROM_START( m4magtbo )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "crmtb14.epr", 0x0000, 0x010000, CRC(79e1746c) SHA1(794317f3aba7b1a7994cde89d81abc2b687d0821) )

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "ctp.chr", 0x0000, 0x000048, CRC(ead61793) SHA1(f38a38601a67804111b8f8cf0a05d35ed79b7ed1) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "scrmtb.snd", 0x000000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END







ROM_START( m4reeltm )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "real.bin", 0x0000, 0x010000, CRC(5bd54924) SHA1(23fcf13c52ee7b9b39f30f999a9102171fffd642) )

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "charter.chr", 0x0000, 0x000048, CRC(4ff4eda2) SHA1(092435e34d79775910316a7bed0f90c4f086e5c4) )

	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )

ROM_END

ROM_START( m4ringfr )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "rof03s.p1", 0x0000, 0x020000, CRC(4b4703fe) SHA1(853ce1f5932e09af2b5f3b5314709f13aa35cf19) )

	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* missing? */
ROM_END






ROM_START( m4roadrn )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dro19", 0x0000, 0x010000, CRC(8b591766) SHA1(df156390b427e31cdda64826a6c1d2457c915f25) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "dro_1.snd", 0x000000, 0x080000, CRC(895cfe63) SHA1(02134e149cef3526bbdb6cb93ef3efa283b9d6a2) )
	ROM_LOAD( "dro_2.snd", 0x080000, 0x080000, CRC(1d5c8d4f) SHA1(15c18ae7286807cdc0feb825b958eae808445690) )
ROM_END




ROM_START( m4royjwl )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "rj.bin", 0x0000, 0x020000, CRC(3ffbe4a8) SHA1(47a0309cc9ff315ad9f64e6855863409443e94e2) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "rj_sound1.bin", 0x000000, 0x080000, CRC(443c4901) SHA1(7b3c6737b47dfe04c072f0e157d83c09340c3f9b) )
	ROM_LOAD( "rj_sound2.bin", 0x080000, 0x080000, CRC(9456523e) SHA1(ea1b6bf16b7d1015c188ad83760336d9851de391) )
ROM_END



ROM_START( m4salsa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dsa15.epr", 0x0000, 0x010000, CRC(22b60b0b) SHA1(4ad184d1557bfd01650684ea9d8ad794fded65f7) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "dsa_1#97c2.snd", 0x0000, 0x080000, CRC(0281a6dd) SHA1(a35a8cd0da32c51f77856ea3eeff7c58fd032333) )
ROM_END






ROM_START( m4showtm )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dsh13.bin", 0x0000, 0x010000, CRC(4ce40ff1) SHA1(f145d6c8e926ca4368d43dacda0fa38615988d84) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "sdsh01s1.snd", 0x0000, 0x080000, CRC(f247ba83) SHA1(9b173503e63a4a861d1380b2ab1fe14af1a189bd) )
ROM_END



























ROM_START( m4steptm )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dst11.bin", 0x0000, 0x010000, CRC(3960f210) SHA1(c7c4fe74cb9a53eaa9114a84240de3bce4ffe75e) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "sdun01.bin", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END







#define M4SUPBJC_EXTRAS \
	ROM_REGION( 0x48, "fakechr", 0 ) \
	ROM_LOAD( "sbj.chr", 0x0000, 0x000048, CRC(cc4b7911) SHA1(9f8a96a1f8b0f9b33b852e93483ce5c684703349) ) \
	ROM_REGION( 0x100000, "altmsm6376", 0 ) \
	ROM_LOAD( "sbjsnd1.hex", 0x000000, 0x080000, CRC(70388bec) SHA1(256fa01b57049d73e88b0bb270fccb555b12dfb7) ) \
	ROM_LOAD( "sbjsnd2.hex", 0x080000, 0x080000, CRC(1d588554) SHA1(48c092ce83d2f881fc217a3d566e896718ad6f24) ) \
	ROM_REGION( 0x100000, "msm6376", 0 ) \
	ROM_LOAD( "sbj.s1", 0x000000, 0x080000, CRC(9bcba966) SHA1(5ced282aca9d39ebf0828aa19357026d5298e955) ) \
	ROM_LOAD( "sbj.s2", 0x080000, 0x080000, CRC(1d588554) SHA1(48c092ce83d2f881fc217a3d566e896718ad6f24) ) \



ROM_START( m4supbjc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sbjs.p1", 0x0000, 0x010000, CRC(f7fb2b99) SHA1(c860d3f95ee3fde02bf00b2e20eeee0ebaf01912) )
	M4SUPBJC_EXTRAS
ROM_END

ROM_START( m4supbjca )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sbjd.p1", 0x0000, 0x010000, CRC(555361f4) SHA1(f5327b811ab3421307dc59d209a216798cd54393) )
	M4SUPBJC_EXTRAS
ROM_END

ROM_START( m4supbjcb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sbjf.p1", 0x0000, 0x010000, CRC(7966deff) SHA1(5cdb6c80ef56b27878eb1fffd6fdf31060e56291) )
	M4SUPBJC_EXTRAS
ROM_END

ROM_START( m4supbjcc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sbjl.p1", 0x0000, 0x010000, CRC(fc47ed74) SHA1(f29b2caac8168410e534e2f224c98dd4bbb9a7f7) )
	M4SUPBJC_EXTRAS
ROM_END

ROM_START( m4supbjcd )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "superbjclub.bin", 0x0000, 0x010000, CRC(68d11d27) SHA1(a0303f845fb5f5b396a7be3ca17a9eaf1a7baef4) )
	M4SUPBJC_EXTRAS
ROM_END


ROM_START( m4supbf )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sbff.p1", 0x0000, 0x010000, CRC(f27feba0) SHA1(157bf28e2d5fc2fa58bed11b3285cf56ae18abb8) )
ROM_END

ROM_START( m4supbfa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sbfs.p1", 0x0000, 0x010000, CRC(c8c52d5e) SHA1(d53513b9faabc307623a7c2f5be0225fb812beeb) )
ROM_END







ROM_START( m4take5 )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "take5.bin", 0x0000, 0x020000, CRC(24beb7d6) SHA1(746beccaf57fd0c54c8cf8d742b8ef50563a40fd) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "tfive1.hex", 0x000000, 0x080000, CRC(70f16892) SHA1(e6448831d3ce7fa251b40023bc7d5d6dee9d6793) )
	ROM_LOAD( "tfive2.hex", 0x080000, 0x080000, CRC(5fc888b0) SHA1(8d50ee4f36bd36aed5d0e7a77f76bd6caffc6376) )
ROM_END




#define M4TECHNO_EXTRAS \
	ROM_REGION( 0x080000, "msm6376", 0 ) \
	ROM_LOAD( "techno.bin", 0x0000, 0x080000, CRC(3e80f8bd) SHA1(2e3a195b49448da11cc0c089a8a9b462894c766b) ) \


ROM_START( m4techno )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dte13.bin", 0x0000, 0x010000, CRC(cf661d06) SHA1(316b2c42e7253a03b2c12b713821045d9f95a8a7) )
	M4TECHNO_EXTRAS
ROM_END

ROM_START( m4technoa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dte13hack.bin", 0x0000, 0x010000, CRC(8b8eafe3) SHA1(93a7714eb4c749b7b19f4f844cf88da9443b0bb7) )
	M4TECHNO_EXTRAS
ROM_END








ROM_START( m4toma )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dtk23.bin", 0x0000, 0x010000, CRC(ffba2b96) SHA1(c7635023ac5181e661e808c6b44ac1add58f4f56) )
ROM_END




ROM_START( m4topdk )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dtd26pj.bin", 0x0000, 0x010000, CRC(1f84d995) SHA1(7412632cf79008b980e48f14aea89c3f8d742ed2) )
ROM_END


ROM_START( m4toprn )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "toprun_v1_1.bin", 0xc000, 0x004000, CRC(9b924324) SHA1(7b155467f30cc22f7cda301ae770fb2a889c9c66) )
	ROM_LOAD( "toprun_v1_2.bin", 0x8000, 0x004000, CRC(940fafa9) SHA1(2a8b669c51c8df50710bd8b552ab30a5d1a136ab) )
ROM_END



#define M4TOPTIM_EXTRAS \
	ROM_REGION( 0x48, "fakechr", 0 ) \
	ROM_LOAD( "ttimer.chr", 0x0000, 0x000048, CRC(f694224e) SHA1(936ab5e349fa59accbb37959cce9519fd97f3978) ) \
	ROM_REGION( 0x080000, "msm6376", 0 ) \
	ROM_LOAD( "toptimer-snd.bin", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) ) \


ROM_START( m4toptim )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "toptimer.bin", 0x0000, 0x010000, CRC(74804012) SHA1(0d9460ba6b1d359d358483c4e8bfd5518f364518) )
	M4TOPTIM_EXTRAS
ROM_END


ROM_START( m4toptima )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dtt2-1.bin", 0x0000, 0x010000, CRC(f9c84a34) SHA1(ad654442f580d6a49658f0e4e39bacbd9d0d0018) )
	M4TOPTIM_EXTRAS
ROM_END





#define M4TROPCL_EXTRAS \
	ROM_REGION( 0x48, "fakechr", 0 ) \
	ROM_LOAD( "tro20.chr", 0x0000, 0x000048, CRC(97618d38) SHA1(7958e99684d50b9bdb56c97f7fcfe161f0824578) ) \


ROM_START( m4tropcl )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "tros.p1", 0x0000, 0x010000, CRC(5e86c3fc) SHA1(ce2419991559839a8875060c1afe0f030190010a) )
	M4TROPCL_EXTRAS
ROM_END

ROM_START( m4tropcla )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "tr2d.p1", 0x0000, 0x010000, CRC(0cc23f89) SHA1(a66c8c28073f53381c43e3e597f15f81c5c61479) )
	M4TROPCL_EXTRAS
ROM_END

ROM_START( m4tropclb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "tr2f.p1", 0x0000, 0x010000, CRC(fbdcd06f) SHA1(27ccdc83e60a62227d33d8cf3d516fc43908ab99) )
	M4TROPCL_EXTRAS
ROM_END

ROM_START( m4tropclc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "tr2s.p1", 0x0000, 0x010000, CRC(6d43375c) SHA1(5be1dc85374c6a1235e0b137b46ebd7a2d7d922a) )
	M4TROPCL_EXTRAS
ROM_END

ROM_START( m4tropcld )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "trod.p1", 0x0000, 0x010000, CRC(60c84612) SHA1(84dc8b34e41436331832c1a32ddac0fce269488a) )
	M4TROPCL_EXTRAS
ROM_END


#define M4TBPLAY_EXTRAS \
	ROM_REGION( 0x48, "fakechr", 0 ) \
	ROM_LOAD( "dtpchr.chr", 0x0000, 0x000048, CRC(7743df66) SHA1(69b1943837ccf8671861ac8ef690138b41de0e5b) ) \
	ROM_REGION( 0x100000, "msm6376", 0 ) \
	ROM_LOAD( "dtps10_1", 0x000000, 0x080000, CRC(d1d2c981) SHA1(6a4940248b0bc8df0a9de0d60e98cfebf1962504) ) \
	ROM_LOAD( "dtps20_1", 0x080000, 0x080000, CRC(f77c4f39) SHA1(dc0e056f4d8c00824b3e672a02da64613bbf204e) ) \


ROM_START( m4tbplay )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dtp13", 0x0000, 0x010000, CRC(de424bc3) SHA1(c82dd56a0b3ccea78325cd90ed8e72ed68a1af77) )
	M4TBPLAY_EXTRAS
ROM_END

ROM_START( m4tbplaya )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "rmtp4b", 0x0000, 0x010000, CRC(33a1764e) SHA1(7475f460dee015a2cd78fc3e0d1d14fd96fdbb9c) )
	M4TBPLAY_EXTRAS
ROM_END

ROM_START( m4tbplayb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "trmyid", 0x0000, 0x010000, CRC(e7af5944) SHA1(64559c97375a3536f7929d7f4d8d19c30527a3ec) )
	M4TBPLAY_EXTRAS
ROM_END













ROM_START( m4twintm )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "d2t11.bin", 0x0000, 0x010000, CRC(6a76ac6f) SHA1(824912ff1fc3155d11d32b597be53481532fdf5e) )

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "m533.chr", 0x0000, 0x000048, CRC(b1d7e29b) SHA1(e8ef07f85780e24b5f406478de50287b740379d9) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "sdun01.bin", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END


ROM_START( m4twist )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "twist_again_mk29-6", 0x8000, 0x008000, CRC(cb331bee) SHA1(a88099a3f35caf02925f1a3f548fbf65c11e3ec9) )
ROM_END

ROM_START( m4twista )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "twistagain-98-mkii.bin", 0x0000, 0x008000, CRC(1cbc7b58) SHA1(eda998a64272fe6796243c2db48ef988b9668c35) )
ROM_END

ROM_START( m4twistb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "twistagain-mki-27.bin", 0x0000, 0x008000, CRC(357f7072) SHA1(8a23509fff79a83a819b27eff8de8db08c679e3f) )
ROM_END




ROM_START( m4univ )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dun20", 0x0000, 0x010000, CRC(6a845d4d) SHA1(82bfc3f3a0ede76a4d482efc71b0390610db7acf) )

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "dunchr.chr", 0x0000, 0x000048, CRC(f694224e) SHA1(936ab5e349fa59accbb37959cce9519fd97f3978) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "sdun01.bin", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END




ROM_START( m4vegastg )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "vs.p1", 0x0000, 0x020000, CRC(4099d572) SHA1(91a7c1575013e61c754b2c2cb841e7687b76d7f9) )

	ROM_REGION( 0x200000, "msm6376", 0 )
	ROM_LOAD( "vssound.bin", 0x0000, 0x16ee37, CRC(456da6be) SHA1(f0e293f0a383878b581326f869c2e49bec61d0c5) )
ROM_END






ROM_START( m4vivalvd )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "dlv11.bin", 0x0000, 0x010000, CRC(a890184c) SHA1(26d9952bf2eb4b55d21cdb934ffc73ff1a1cfbac) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "vegssnd.bin", 0x0000, 0x080000, CRC(93fd4253) SHA1(69feda7ffc56defd515c9cd1ce204af3d9731a3f) )
ROM_END














ROM_START( m4wildtm )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "wildtimer.bin", 0x0000, 0x010000, CRC(5bd54924) SHA1(23fcf13c52ee7b9b39f30f999a9102171fffd642) )

	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "charter.chr", 0x0000, 0x000048, CRC(4ff4eda2) SHA1(092435e34d79775910316a7bed0f90c4f086e5c4) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "wildtimer-snd.bin", 0x0000, 0x080000, CRC(50450909) SHA1(181659b0594ba8d196b7130c5999c91676a363c0) )
ROM_END



ROM_START( m4ch30 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ch301s", 0x0000, 0x010000, CRC(d31c9081) SHA1(21d1f4cc3de2343d830e3ee02e3a53abd12b6b9d) )

	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* missing */
ROM_END


















ROM_START( m4czne )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "czone 6.bin", 0x0000, 0x010000, CRC(e5b2b64e) SHA1(b73a2aed7b04184bc7c5c3d0a11d44e624a47428) )
ROM_END

ROM_START( m4fourmr )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "frmr5p26.bin", 0x8000, 0x008000, CRC(f0c5bd8a) SHA1(39026459008ed5b5bd3a10841799227fef70e5b5) )
ROM_END

ROM_START( m4holywd )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "hollywood 5p.bin", 0x0000, 0x010000, CRC(fb4ebb6e) SHA1(1ccfa81c173011ce70640097c85b532fd44f5a6e) )
ROM_END






#define M4LAZY_EXTRAS \
	ROM_REGION( 0x180000, "msm6376", ROMREGION_ERASE00 ) \
	/* missing? */ \


ROM_START( m4lazy )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "lb_sj___.1_0", 0x0000, 0x020000, CRC(8628dcf1) SHA1(80cb9348e2704d0f72a44b4aa74b24fe03e279bc) )
	M4LAZY_EXTRAS
ROM_END

ROM_START( m4lazya )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "lb_sj___.1_2", 0x0000, 0x020000, CRC(2b906f52) SHA1(802bcf6b3679e135308026752a55e55f00f21e85) )
	M4LAZY_EXTRAS
ROM_END

ROM_START( m4lazyb )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "lb_sj_d_.1_2", 0x0000, 0x020000, CRC(a7691bad) SHA1(6cda3f3c18c13c04dbe0e4c1e4c817eedc34aa92) )
	M4LAZY_EXTRAS
ROM_END


















ROM_START( m4specu )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "speculator.bin", 0x8000, 0x008000, CRC(4035d20c) SHA1(4a534294c5c7332eacd09ca44f351d6a6850cc29) )
ROM_END









ROM_START( m4sunclb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sucxe__0.2", 0x0000, 0x010000, CRC(fd702a6f) SHA1(0f6d553fcb096ca4874bb971425dabfbe18db31d) )
ROM_END

ROM_START( m4sunclba )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sucxed_0.2", 0x0000, 0x010000, CRC(70802bc3) SHA1(69b36f716cb608931f933cb58e47232b18064f9d) )
ROM_END



ROM_START( m4sunscl )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sc_xe___.3_3", 0x0000, 0x010000, CRC(e3732cc6) SHA1(77f0368bb29ad00030f83af794a52df92fe97e5d) )
ROM_END

ROM_START( m4sunscla )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sc_xe_d_.3_3", 0x0000, 0x010000, CRC(b8627c4a) SHA1(ad616d38773cbd82376b518aa15dc3d7027237c5) )
ROM_END

ROM_START( m4sunsclb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sc_xef__.3_3", 0x0000, 0x010000, CRC(8e7e1100) SHA1(7648ea860a546081388a213845e27312730f46d9) )
ROM_END
















ROM_START( m4aao )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "aao2_8.bin", 0x0000, 0x010000, CRC(94ce4016) SHA1(2aecb6dbe798b7bbfb3d27f4d115b6611c7d990f) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "aaosnd.bin", 0x0000, 0x080000, CRC(7bf30b96) SHA1(f0086ae239b1d973018a3ea04e816a87f8f20bad) )
ROM_END



ROM_START( m4bandgd )
	ROM_REGION( 0x020000, "maincpu", 0 )
	ROM_LOAD( "bog.bin", 0x0000, 0x020000, CRC(21186fb9) SHA1(3d536098c7541cbdf02d68a18a38cae71155d7ff) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "bandsofgoldsnd.bin", 0x0000, 0x080000, CRC(95c6235f) SHA1(a13afa048b73fabfad229b5c2f8ef5ee9948d9fb) )
ROM_END



ROM_START( m4bigben )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "b_bv2_7.bin", 0x0000, 0x010000, CRC(9f3a7638) SHA1(b7169dc26a6e136d6daaf8d012f4c3d017e99e4a) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "big-bensnd1.bin", 0x000000, 0x080000, CRC(e41c3ec1) SHA1(a0c09f51229afcd14f09bb9080d4f3bb198b2050) )
	ROM_LOAD( "big-bensnd2.bin", 0x080000, 0x080000, CRC(ed71dbe1) SHA1(e67ca3c178caacb99118bacfcd7612e699f40455) )
ROM_END

ROM_START( m4bigbena )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "b_bv2_9.bin", 0x0000, 0x010000, CRC(86a745ee) SHA1(2347e8e38c743ea4d00faee6a56bb77e05c9c94d) ) // aka bb2_9.bin

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "big-bensnd1.bin", 0x000000, 0x080000, CRC(e41c3ec1) SHA1(a0c09f51229afcd14f09bb9080d4f3bb198b2050) )
	ROM_LOAD( "big-bensnd2.bin", 0x080000, 0x080000, CRC(ed71dbe1) SHA1(e67ca3c178caacb99118bacfcd7612e699f40455) )
ROM_END

ROM_START( m4bigbenb )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "bb1_9p.bin", 0x0000, 0x010000, CRC(c76c5a09) SHA1(b0e3b38998428f535841ab5373d57cb0d5b21ed3) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "big-bensnd1.bin", 0x000000, 0x080000, CRC(e41c3ec1) SHA1(a0c09f51229afcd14f09bb9080d4f3bb198b2050) )
	ROM_LOAD( "big-bensnd2.bin", 0x080000, 0x080000, CRC(ed71dbe1) SHA1(e67ca3c178caacb99118bacfcd7612e699f40455) )
ROM_END



ROM_START( m4bigbend )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "bb_2_1.bin", 0x0000, 0x010000, CRC(d3511805) SHA1(c86756998d36e729874c71a5d6442785069c57e9) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "big-bensnd1.bin", 0x000000, 0x080000, CRC(e41c3ec1) SHA1(a0c09f51229afcd14f09bb9080d4f3bb198b2050) )
	ROM_LOAD( "big-bensnd2.bin", 0x080000, 0x080000, CRC(ed71dbe1) SHA1(e67ca3c178caacb99118bacfcd7612e699f40455) )
ROM_END

ROM_START( m4bigbene )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "bbs_2_9p.bin", 0x0000, 0x010000, CRC(0107608d) SHA1(9e5def90e77f65c366aea2a9ac24d5f17c4d0ae8) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "big-bensnd1.bin", 0x000000, 0x080000, CRC(e41c3ec1) SHA1(a0c09f51229afcd14f09bb9080d4f3bb198b2050) )
	ROM_LOAD( "big-bensnd2.bin", 0x080000, 0x080000, CRC(ed71dbe1) SHA1(e67ca3c178caacb99118bacfcd7612e699f40455) )
ROM_END





ROM_START( m4boltbl )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "bfb.bin", 0x8000, 0x008000, CRC(63058a6b) SHA1(ebccc647a937c36ffc6c7cfc01389f04f829999c) )
ROM_END

ROM_START( m4boltbla )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "bfb1.1.bin", 0x8000, 0x008000, CRC(7a91122d) SHA1(28229e86feb4411978e556f7f7bd85bfd996b8aa) )
ROM_END

ROM_START( m4boltblb )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "bfb9 5p cash.bin", 0x8000, 0x008000, CRC(792bff34) SHA1(6996e87f22df6bac7bbe9908534b7e0480f03ede) )
ROM_END

ROM_START( m4boltblc )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "bolt-gilwern.bin", 0x8000, 0x008000, CRC(74e2c821) SHA1(1dcdc58585d1dcfc93e2aeb3df0cd41705cde196) )
ROM_END

ROM_START( m4dblchn )
	ROM_REGION( 0x010000, "maincpu", 0 )
	ROM_LOAD( "doublechance.bin", 0x0000, 0x010000, CRC(6feeeb7d) SHA1(40fe67d854fbf48959e08fdb5743e14d340c16e7) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "doublechancesnd.bin", 0x0000, 0x080000, CRC(3e80f8bd) SHA1(2e3a195b49448da11cc0c089a8a9b462894c766b) )
ROM_END


ROM_START( m4kqclub )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "kingsque.p1", 0x8000, 0x008000, CRC(6501e501) SHA1(e289a9418c640415967fafda43f20877b38e3671) )
ROM_END

ROM_START( m4snookr )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "snooker.ts2", 0x8000, 0x004000, CRC(a6906eb3) SHA1(43b91e88f909b758f880d83df4f889f15aa17eb3) )
	ROM_LOAD( "snooker.ts1", 0xc000, 0x004000, CRC(3e3072dd) SHA1(9ea8b270044b48767a2e6c19e8ed257d5491c1d0) )
ROM_END



ROM_START( m4stakex )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "stakex.bin", 0x0000, 0x010000, CRC(098c7117) SHA1(27f04cfb88ef870fc30afd055cf32ffe448275ea) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "stakexsnd.bin", 0x0000, 0x080000, CRC(baf17991) SHA1(282e0ac9d18299e9f7a0fecaf9edf0cb4205ef0e) )
ROM_END

ROM_START( m4stakexa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "stakex2.bin", 0x0000, 0x010000, CRC(77ae3f63) SHA1(c5f1cfd5bffcf3156f584757de57ef6530214511) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "stakexsnd.bin", 0x0000, 0x080000, CRC(baf17991) SHA1(282e0ac9d18299e9f7a0fecaf9edf0cb4205ef0e) )
ROM_END


ROM_START( m4stand2 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "stand 2 del 8.bin", 0x08000, 0x08000, CRC(a9a5edc7) SHA1(035d3f3b3373cec475753f1b0de2f4db48d6d288) )
ROM_END










ROM_START( m4bigban )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "big04.p1", 0x0000, 0x020000, CRC(f7ead9c6) SHA1(46c10abb892cb6d427ad508aae96752c14b4cb83) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* Missing? */
ROM_END

ROM_START( m4crzcsn )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "crz03.bin", 0x0000, 0x020000, CRC(48610c4f) SHA1(a62ac8b3ee704ee4e98f9d56bfc723d4cbb25b54) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* Missing? */
ROM_END

ROM_START( m4crzcav )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "gcv05.p1", 0x0000, 0x020000, CRC(b9ba46f6) SHA1(78b745d85b36444c39747982987088a772b20a7e) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* Missing? */
ROM_END

ROM_START( m4dragon )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "dgl01.p1", 0x0000, 0x020000, CRC(d7d39c9b) SHA1(5350c9db549edee30815516b1ce74a018390ff3d) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* Missing? */
ROM_END

ROM_START( m4hilonv )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "hnc02.p1", 0x0000, 0x020000, CRC(33a8022b) SHA1(5168b8f32630aa2cb56f30c941695f1728e4fb7a) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* Missing? */
ROM_END

ROM_START( m4octo )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "oct03.p1", 0x0000, 0x020000, CRC(8df66e94) SHA1(e1ab93982846d83becae36b5814ebbd515b9078e) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* Missing? */
ROM_END

ROM_START( m4sctagt )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "gse3_0.p1", 0x0000, 0x010000, CRC(eff705ff) SHA1(6bf96872ef4bcc8f8041c5384d892f072c72be2b) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* Missing? */
ROM_END










ROM_START( m4cld02 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cru0_2.bin", 0x0000, 0x010000, CRC(e3c01944) SHA1(33a2b2c05686f53811349b2980e590fdc4b72756) )
	ROM_REGION( 0x080000, "msm6376", ROMREGION_ERASE00 )
	/* missing */
ROM_END

ROM_START( m4barcrz )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "barcrazy.bin", 0x0000, 0x010000, CRC(917ad749) SHA1(cb0a3f6737b8f183d2efb0a3f8adbf86d40a38ff) )

	ROM_REGION( 0x080000, "msm6376", 0 )
	ROM_LOAD( "barcrazysnd.bin", 0x0000, 0x080000, CRC(0e155193) SHA1(7583e9f3e3624f82f2329565bdcbdaa5a5b03ee0) )
ROM_END

ROM_START( m4bonzbn )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "bingo-bonanza_v1.bin", 0x0000, 0x010000, CRC(3d137ddf) SHA1(1ce23db111448e44a166554dd8853dc379e787da) )

	ROM_REGION( 0x100000, "msm6376", 0 )
	ROM_LOAD( "bingo-bonanzasnd1.bin", 0x000000, 0x080000, CRC(e0eb2a92) SHA1(cbc0b3bba7857d87535d1c2a7459aed60709734a) )
	ROM_LOAD( "bingo-bonanzasnd2.bin", 0x080000, 0x080000, CRC(7db27b28) SHA1(98c5fa4bf8c7f67fae90a1ca98b74057f5ed9b6b) )
ROM_END

ROM_START( m4dnj )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "d.n.j 1-02", 0x0000, 0x010000, CRC(5750843d) SHA1(b87923e84071ea4a1af7566a7f413f8e30e208e9) )
ROM_END

ROM_START( m4dnja )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "d.n.j 1-03", 0x0000, 0x010000, CRC(7b805255) SHA1(f62765bfa66e2422ac0a71ebaff27f1ccd470fe2) )
ROM_END

ROM_START( m4dnjb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "d.n.j 1-06", 0x0000, 0x010000, CRC(aab770c7) SHA1(f24fff8346915017bc43fef9fac356a067676d86) )
ROM_END


ROM_START( m4matdr )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "matador.bin", 0x0000, 0x020000, CRC(367788a4) SHA1(3c9b077a64f993cb60107558efdfcbee0fe5c958) )

	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	/* missing */
ROM_END



ROM_START( m4hslo )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "hot30", 0x0000, 0x010000, CRC(62f2c420) SHA1(5ae89a1b585738255e8d9ae153c3c63b4a2893e4) )
ROM_END

#define M4SBX_EXTRAS \
	ROM_REGION( 0x40000, "upd", 0 ) /* not oki at least... */ \
	ROM_LOAD( "sbsnd", 0x0000, 0x040000, CRC(27fd9fe6) SHA1(856fdc95a833affde0ada7041c68a4b6b729b715) ) \


ROM_START( m4sbx )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sbx-2.1-cash.bin", 0x8000, 0x008000, CRC(2dca703e) SHA1(aef398f4ed38ba34f28009058c9486a570f64e0f) )
	M4SBX_EXTRAS
ROM_END

ROM_START( m4sbxa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "b_sbx23.bin", 0x8000, 0x008000, CRC(8188e94f) SHA1(dfbfc549d12c8f7c7db6c12ba766c28f1cf0873f) )
	M4SBX_EXTRAS
ROM_END

ROM_START( m4sbxb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "s bears v1-4 20p po.bin", 0x8000, 0x008000, CRC(03486714) SHA1(91c237956bbec58cc08a3e92543488d8e2daa673) )
	M4SBX_EXTRAS
ROM_END

ROM_START( m4sbxc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "s bears v2-4 10p 8.bin", 0x8000, 0x008000, CRC(9b94f8d0) SHA1(9808386def14c8a058730e90135a4d6506e6ed3d) )
	M4SBX_EXTRAS
ROM_END

ROM_START( m4sbxd )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "s bears v2-4 20p po.bin", 0x8000, 0x008000, CRC(ad8f8d9d) SHA1(abd808f95b587a84e8b3aad1af9fe1cb613c9821) )
	M4SBX_EXTRAS
ROM_END

ROM_START( m4sbxe )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "superbea.10p", 0x8000, 0x008000, CRC(70020466) SHA1(473c9feb9ce0024b870612af19ec8a47a7798506) )
	M4SBX_EXTRAS
ROM_END



ROM_START( m4bclimb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "bc8pv4.bin", 0x8000, 0x008000, CRC(229a7607) SHA1(b20b2c9f9d19ccd6146affdf519fa4bc0322c971) )

	ROM_REGION( 0x40000, "upd", 0 ) // not oki at least...
	ROM_LOAD( "sbsnd", 0x0000, 0x040000, CRC(27fd9fe6) SHA1(856fdc95a833affde0ada7041c68a4b6b729b715) )
ROM_END

ROM_START( m4captb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "c_bear21.rom", 0x8000, 0x008000, CRC(2e9a42e9) SHA1(0c3f33311f1543daf2ff5c0443dc8c000d49c26d) )

	ROM_REGION( 0x40000, "upd", ROMREGION_ERASE00 ) // not oki at least...
//  ROM_LOAD( "sbsnd", 0x0000, 0x040000, CRC(27fd9fe6) SHA1(856fdc95a833affde0ada7041c68a4b6b729b715) )
ROM_END

#define M4JUNGJ_EXTRAS \
	ROM_REGION( 0x40000, "upd", ROMREGION_ERASE00 ) \
	/* missing? */ \

ROM_START( m4jungj )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "jj2410p.bin", 0x8000, 0x008000, CRC(490838c6) SHA1(a1e9963df9a429ae594592312e977f22f96c6073) )
	M4JUNGJ_EXTRAS
ROM_END

ROM_START( m4jungja )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "jj2420p.bin", 0x8000, 0x008000, CRC(39329ccf) SHA1(6b79e4fc553bad935ec9989ad5ef3e186e720633) )
	M4JUNGJ_EXTRAS
ROM_END

ROM_START( m4jungjb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "jjv2_4p.bin", 0x8000, 0x008000, CRC(125a8138) SHA1(18c62df5b331bd09d6dcda6280351e94b7b816fd) )
	M4JUNGJ_EXTRAS
ROM_END

ROM_START( m4jungjc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "jjv4.bin", 0x8000, 0x008000, CRC(bf583156) SHA1(084c5ed3d96c92f265ad08cc7aed7fe6092217a5) )
	M4JUNGJ_EXTRAS
ROM_END


#define M4FSX_EXTRAS \
	ROM_REGION( 0x40000, "upd", ROMREGION_ERASE00 ) \
	/* missing? */ \


ROM_START( m4fsx )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD("funspotx.10p", 0x8000, 0x008000, CRC(55199f36) SHA1(7af376781e381582b06972725a2022cc28ba60b3) )
	M4FSX_EXTRAS
ROM_END

ROM_START( m4fsxa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "funspotx.20p", 0x8000, 0x008000, CRC(08d1eb6e) SHA1(7c7c02d9c34696d75490df8596ffe64fba93dcc4) )
	M4FSX_EXTRAS
ROM_END

ROM_START( m4fsxb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "b_fsv1.bin", 0x8000, 0x008000, CRC(b077f944) SHA1(97d96594b8d2d7232bad087cc55912dec02d7484) )
	M4FSX_EXTRAS
ROM_END

#define M4CCOP_EXTRAS \
	ROM_REGION( 0x100000, "alt1msm6376", ROMREGION_ERASE00 ) \
	ROM_LOAD( "cash-copssnd1-de.bin", 0x000000, 0x080000, CRC(cd03f7f7) SHA1(4c09a86bcdf9a9eb224b19b932b75c9db3784fad) ) \
	ROM_LOAD( "cash-copssnd2-de.bin", 0x080000, 0x080000, CRC(107816a2) SHA1(f5d4a0390b85a665a3536da4689ec91b1a2da3ae) ) \
	ROM_REGION( 0x100000, "alt2msm6376", ROMREGION_ERASE00 ) \
	ROM_LOAD( "cash-copssnd1.bin", 0x000000, 0x080000, CRC(776a303d) SHA1(a5a282674674f25bc6ca169eeebee7309239871f) ) \
	ROM_LOAD( "cash-copssnd2.bin", 0x080000, 0x080000, CRC(107816a2) SHA1(f5d4a0390b85a665a3536da4689ec91b1a2da3ae) ) \
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 ) \
	ROM_LOAD( "cashcops.p1", 0x000000, 0x080000, CRC(9a59a3a1) SHA1(72cfc99b22ec5fb89714c6d2d66760d86dc19f2f) ) \
	ROM_LOAD( "cashcops.p2", 0x080000, 0x080000, CRC(deb3e755) SHA1(01f92881c451919be549a1c58afa1fa4630bf171) ) \


ROM_START( m4ccop )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cashcop9.bin", 0x0000, 0x010000, CRC(5f993207) SHA1(ab0614e6a1355d275158b1a32f65086e40c2f890) )
	M4CCOP_EXTRAS
ROM_END

ROM_START( m4ccopa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cash-cops_v4-de.bin", 0x0000, 0x010000, CRC(df3da824) SHA1(c275a33e4a89f1b9ecbae80cb7b62007b29b9fd2) )
	M4CCOP_EXTRAS
ROM_END

ROM_START( m4ccopb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "cashcop8.bin", 0x0000, 0x010000, CRC(165603df) SHA1(d301696a340ed136a43c5753c8bf73283a925fd7) )
	M4CCOP_EXTRAS
ROM_END

ROM_START( m4ccc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "ccc12.bin", 0x8000, 0x008000, CRC(570cc766) SHA1(036c95ff6428ab38cceb0537dcc990be78fb331a) )

	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	ROM_LOAD( "criss cross crazy sound (27c2001)", 0x0000, 0x040000, CRC(1994c509) SHA1(2bbe91a43aa9953b7776faf67e81e30a4f7b7cb2) )
ROM_END


ROM_START( m4treel )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "trgv1.1s", 0x0000, 0x010000, CRC(a9c76b08) SHA1(a5b3bc980eb58e346cb02d8ca43401f304e5b6de) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4treela )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "trgv1.1b", 0x0000, 0x020000, CRC(7eaebef6) SHA1(5ab86329041e7df09cc2e3ce8d5afd44d88c246c) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
ROM_END



ROM_START( m4unkjok )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "joker 10p 3.bin", 0x0000, 0x010000, CRC(009823ac) SHA1(5ab25da5876c87a8d8701f84446bb3d377e4c1ca) )
ROM_END

ROM_START( m4unkjoka )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "joker 10p 6.bin", 0x0000, 0x010000, CRC(f25f0704) SHA1(35298b49f79c5029277f4777fe88d5e4344c115f) )
ROM_END

ROM_START( m4unkjokb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "joker 20p 3 or 6.bin", 0x0000, 0x010000, CRC(cae4397e) SHA1(53b61fd41c97a6ed29ce6a7b555e061ecf2b0ae2) )
ROM_END

ROM_START( m4unkjokc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "joker new 20p 6 or 3.bin", 0x0000, 0x010000, CRC(b8d77b97) SHA1(54f69823bb3fd9c2cca014dc7c51913b2d6c8058) )
ROM_END

ROM_START( m4remag )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "remagv2", 0x0000, 0x010000, CRC(80d9c1c2) SHA1(c77d443d92084c324ef75575acca66ffbd9beef3) )
ROM_END

ROM_START( m4rmg )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "rmgicdd", 0x0000, 0x010000, CRC(bd64be0d) SHA1(772b80619c7d514a7a253f35137896d6a73bf4c6) )
ROM_END

ROM_START( m4wnud )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "wnudge.bin", 0x8000, 0x008000, CRC(1d935575) SHA1(c4177c41473c0fb511e0ee035961f55ad43be14d) )
ROM_END

ROM_START( m4t266 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "t2 66.bin", 0x0000, 0x010000, CRC(5c99c6bb) SHA1(7b74e0e5207c00b31cb1859e0cc458c0412a1a07) )
ROM_END

ROM_START( m4brnze )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "bv25", 0x0000, 0x010000, CRC(5c66f460) SHA1(c7587a6e992549ad8814f77c65b33a17a3641431) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4brnzea )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "bv25v2", 0x0000, 0x010000, CRC(a675edb3) SHA1(a3c6ee6a0bfb301fed72b45ee8e363d77b8b8dbb) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4brnzeb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "bv55", 0x0000, 0x010000, CRC(93905bc9) SHA1(e8d3cd125dced43fc2cf23cbccc59110561d2a40) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4riotrp )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "drt10.bin", 0x0000, 0x010000, CRC(a1badb8a) SHA1(871786ea4e65ecbf61c9a776100321253922d11e) )

	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
	ROM_LOAD( "dblcsnd.bin", 0x0000, 0x080000, CRC(c90fa8ad) SHA1(a98f03d4b6f5892333279bff7537d4d6d887da62) )
ROM_END















#define M4SURF_EXTRAS \
	ROM_REGION( 0x200000, "msm6376", 0 ) \
	ROM_LOAD( "s_surf.sn1", 0x000000, 0x080000, CRC(f20a7d69) SHA1(7887230613b497dc71a60125dd1e265ebbc8eb23) ) \
	ROM_LOAD( "s_surf.sn2", 0x080000, 0x080000, CRC(6c4a9074) SHA1(3b993120156677de893e5dc1e0c5d6e0285c5570) ) \


ROM_START( m4surf )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "s_surfin._pound5", 0x0000, 0x020000, CRC(5f800636) SHA1(5b1789890eea44e5275e13f360876374d862935f) )
	M4SURF_EXTRAS
ROM_END

ROM_START( m4surfa )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "s_surfin.upd", 0x0000, 0x020000, CRC(d0bef9cd) SHA1(9d53bfe8d928b190202bf747c0d7bb4cc0ae0efd) )
	M4SURF_EXTRAS
ROM_END

ROM_START( m4surfb )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "s_surfin._pound15", 0x0000, 0x020000, CRC(eabce7fd) SHA1(4bb2bbcc7d2917eca72385a21ab85d2d94a882ec) )
	M4SURF_EXTRAS
ROM_END


ROM_START( m4wife )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "moy_wife.p1", 0x0000, 0x020000, CRC(293d35a6) SHA1(980a28ca5e9ec3ca2e1a5b34f658b622dca4cf50) )

	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
	// missing?
ROM_END

#define M4BLKGD_EXTRAS \
	ROM_REGION( 0x200000, "msm6376", 0 ) \
	ROM_LOAD( "blackgoldsnd1.bin", 0x000000, 0x080000, CRC(d251b59e) SHA1(960b81b87f0fb5000028c863892a273362cb897f) ) \
	ROM_LOAD( "blackgoldsnd2.bin", 0x080000, 0x080000, CRC(87cbcd1e) SHA1(a6cd186af7c5682e216f549b77735b9bf1b985ae) ) \
	ROM_LOAD( "blackgoldsnd3.bin", 0x100000, 0x080000, CRC(258f7b83) SHA1(a6df577d98ade8c5c5ff68ef891667e65e83ac17) ) \

ROM_START( m4blkgd )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "blackgoldprg.bin", 0x0000, 0x080000, CRC(a04736b2) SHA1(9e060cc79e7922b38115f1412ed76f8c76deb917) )
	M4BLKGD_EXTRAS
ROM_END

ROM_START( m4blkgda )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "blackgoldversion2.4.bin", 0x0000, 0x040000, CRC(fad4e360) SHA1(23c6a13e8d1ca307b0ef22edffed536675985aca) )
	M4BLKGD_EXTRAS
ROM_END

#define M4ZILL_EXTRAS \
	ROM_REGION( 0x200000, "msm6376", 0 ) \
	ROM_LOAD( "zillsnd.bin", 0x0000, 0x080000, CRC(171ed677) SHA1(25d63f4d9c64f13bec4feffa265c5b0c5f6be4ec) ) \


ROM_START( m4zill )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "zillprgh.bin", 0x0000, 0x080000, CRC(6f831f6d) SHA1(6ab6d7f1752d27bc216bc11533b90178ce188715) )
	M4ZILL_EXTRAS
ROM_END

ROM_START( m4zilla )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "zillprog.bin", 0x0000, 0x080000, CRC(0f730bab) SHA1(3ea82c8f7d62c70897a5c132273820c9f192cd72) )
	M4ZILL_EXTRAS
ROM_END


#define M4HSTR_EXTRAS \
	ROM_REGION( 0x200000, "altmsm6376", 0 ) \
	ROM_LOAD( "happystreak.p1", 0x0000, 0x080000, CRC(b1f328ff) SHA1(2bc6605965cb5743a2f8b813d68cf1646a4bcac1) ) \
	ROM_REGION( 0x200000, "msm6376", 0 ) \
	ROM_LOAD( "happystreaksnd.p1", 0x0000, 0x080000, CRC(76cda195) SHA1(21a985cd6cf1f63f4aa799563099a0527a7c0ea2) ) \
	ROM_LOAD( "happystreaksnd.p2", 0x080000, 0x080000, CRC(f3b4c763) SHA1(7fd6230c13b66a16daad9d45935c7803a5a4c35c) ) \


ROM_START( m4hstr )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "h_s_v1_2.bin", 0x0000, 0x010000, CRC(ef3d3461) SHA1(aa5b1934ab1c6739f36ac7b55d3fda2c640fe4f4) )
	M4HSTR_EXTRAS
ROM_END

ROM_START( m4hstra )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "hs2_5.bin", 0x0000, 0x010000, CRC(f669a4c9) SHA1(46813ba7104c97eaa851b50019af9b80046d03b3) )
	M4HSTR_EXTRAS
ROM_END

ROM_START( m4hstrb )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "hs2_5p.bin", 0x0000, 0x010000, CRC(71c981aa) SHA1(5effe7487e7216078127d3dc4a0a7ad02ad84390) )
	M4HSTR_EXTRAS
ROM_END


ROM_START( m4hstrcs )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "chs3_6.bin", 0x0000, 0x010000, CRC(d097ae0c) SHA1(bd78c14e7f057f173859bcb1db5e6a142d0c4062) )
	M4HSTR_EXTRAS
ROM_END

ROM_START( m4hstrcsa )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "chs3_6p.bin", 0x0000, 0x010000, CRC(57378b6f) SHA1(cf1cf528b9790c1013d87ccf63dcbf59f365067f) )
	M4HSTR_EXTRAS
ROM_END

ROM_START( m4hstrcsb )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "chs3_6pk.bin", 0x0000, 0x010000, CRC(f95f1afe) SHA1(fffa409e8c7148a840d5dedf490fd9f6975e9476) )
	M4HSTR_EXTRAS
ROM_END

ROM_START( m4hstrcsc )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "chs3_6k.bin", 0x0000, 0x010000, CRC(7eff3f9d) SHA1(31dedb0d9476633e8eb947a687c7b8a94b0e182c) )
	M4HSTR_EXTRAS
ROM_END

ROM_START( m4hstrcsd )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "chs_4_2.bin", 0x0000, 0x010000, CRC(ec148b65) SHA1(2d6252ce68719281f5597955227a1f662743f006) )
	M4HSTR_EXTRAS
ROM_END


#define M4DDB_EXTRAS \
	ROM_REGION( 0x200000, "msm6376", 0 ) \
	ROM_LOAD( "ddbsound1", 0x000000, 0x080000, CRC(47c87bd5) SHA1(c1578ae553c38e93235cea2142cb139170de2a7e) ) \
	ROM_LOAD( "ddbsound2", 0x080000, 0x080000, CRC(9c733ab1) SHA1(a83c3ebe99703bb016370a8caf76bdeaff5f2f40) ) \

ROM_START( m4ddb )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "ddb3_1.bin", 0x0000, 0x010000, CRC(3b2da727) SHA1(8a677be3b82464d1bf1e97d22adad3b27374079f) )
	M4DDB_EXTRAS
ROM_END

ROM_START( m4ddba )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "ddb3_1p.bin", 0x0000, 0x010000, CRC(bc8d8244) SHA1(9b8e0706b3add42e5e4a8b6c6a2f80a333a2f49e) )
	M4DDB_EXTRAS
ROM_END


ROM_START( m4hapfrt )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "hf1_1.bin", 0x0000, 0x010000, CRC(6c16cb05) SHA1(421b164c8410629956177355e505859757c97a6b) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4hapfrta )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "hf1_1p.bin", 0x0000, 0x010000, CRC(ebb6ee66) SHA1(1f9b67260e5becd013d95358cc89acb1099d655d) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4hapfrtb )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "hf1_4pk.bin", 0x0000, 0x010000, CRC(0944b3c6) SHA1(00cdb75dda4f8984f77806047ad79fe9a1a8760a) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END








ROM_START( m4sunday )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "sunday_sport_v11", 0x0000, 0x010000, CRC(14147d59) SHA1(03b14f4f83a545b3252702267ac012b3be76013d) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4jp777 )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "jpot71", 0x0000, 0x010000, CRC(f4564a05) SHA1(97d21e2268e5d99e6e51cb12c45e09445cff1f50) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4booze )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "boozecruise10_v10.bin", 0x0000, 0x010000, CRC(b37f752b) SHA1(166f7d17694689bd9d51d859c13ddafa1c6e5e7f) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4cbing )
	ROM_REGION( 0x80000, "maincpu", 0 )
	ROM_LOAD( "cherrybingoprg.bin", 0x0000, 0x010000, CRC(00c1d4f3) SHA1(626df7f2f597ed13c32ce0fa8846f2e27ca68eae) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 ) // not oki!
	ROM_LOAD( "cherrybingosnd.p1", 0x000000, 0x100000, CRC(11bed9f9) SHA1(63ed45122dda8e412bb1eaeb967d8a0f925d4bde) )
	ROM_LOAD( "cherrybingosnd.p2", 0x100000, 0x100000, CRC(b2a7ec28) SHA1(307f19ffb46f4a2e8e93923ddb666e50de43a00e) )
ROM_END



ROM_START( m4nod )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "nod.bin", 0x0000, 0x010000, CRC(bc738af5) SHA1(8df436139554ccfb48c4db0a32e3333dbf3c4f46) )
	ROM_REGION( 0x200000, "upd", ROMREGION_ERASE00 )
	ROM_LOAD( "nodsnd.bin", 0x0000, 0x080000, CRC(2134494a) SHA1(3b665bf79567a71195b20e76c50b02707d15b78d) )
ROM_END





ROM_START( m4aliz )
	ROM_REGION( 0x40000, "maincpu", 0 )
	ROM_LOAD( "70000000.bin", 0x0000, 0x040000, CRC(56f64dd9) SHA1(11f990c9a6864a969dc9a4146e1ac2c963e3eb9b) )

	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
	ROM_LOAD( "alizsnd.hi", 0x0000, 0x080000, CRC(c7bd937a) SHA1(cc4d85a3d4cdf57fa96c812a4cd78b599c7052ff) )
	ROM_LOAD( "alizsnd.lo", 0x080000, 0x04e15e, CRC(111cc111) SHA1(413efedbc9e85240df833c10d680b0e907da10b3) )

	ROM_REGION( 0x200000, "misc", ROMREGION_ERASE00 ) // i think this is just the sound roms as intelhex
	ROM_LOAD( "71000000.hi", 0x0000, 0x0bbe9c, CRC(867058c1) SHA1(bd980cb0bb3075854cc2e9b829c31f3742f4f1c2) )
	ROM_LOAD( "71000000.lo", 0x0000, 0x134084, CRC(53046751) SHA1(b8f9eca933315b497732c895f4311f62103344fc) )
ROM_END




ROM_START( m4c2 )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "ci2-0601.bin", 0x0000, 0x010000, CRC(84cc8aca) SHA1(1471e3ad9c9ba957b6cc99c204fe588cc55fbc50) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END


ROM_START( m4coney )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "70000060.bin", 0x0000, 0x010000, CRC(fda208e4) SHA1(b1a243b2681faa03add4ab6e4df98814f9c52fc5) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END





ROM_START( m4goldnn )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "goldenyears10.bin", 0x0000, 0x020000, CRC(1074bac6) SHA1(967ee64f267a80017fc95bbc6c5a38354e9cab65) )

	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
	ROM_LOAD( "tgyosnd.p1", 0x000000, 0x080000, CRC(bda49b46) SHA1(fac143003641824bf0db4ac6841292e509fa00da) )
	ROM_LOAD( "tgyosnd.p2", 0x080000, 0x080000, CRC(43d28a0a) SHA1(5863e493e84641e4fabcd69e6402e3bcca87dde2) )
	ROM_LOAD( "tgyosnd.p3", 0x100000, 0x080000, CRC(b5b9eb68) SHA1(8d5a0a687dd7096da8dfd2a59c6fe96f4b1949f9) )
ROM_END






ROM_START( m4mgpn )
	ROM_REGION( 0x40000, "maincpu", 0 )
	ROM_LOAD( "mgp15.p1", 0x0000, 0x010000, CRC(ec76233f) SHA1(aa8595c639c83026d7fe5c3a161f8b08ff9a8b46) )

	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
	ROM_LOAD( "mgpsnd.p1", 0x000000, 0x080000, CRC(d5f0b845) SHA1(6d97d0d4d07407bb0a51e1d62da95c664418a9e9) )
	ROM_LOAD( "mgpsnd.p2", 0x080000, 0x080000, CRC(cefeea06) SHA1(45142ca1bab898dc6f3c32e382ee9157132810a6) )
	ROM_LOAD( "mgpsnd.p3", 0x100000, 0x080000, CRC(be4b3bd0) SHA1(f14c08dc770a24db8bbd00a65d3edf6ee9895ca3) )
	ROM_LOAD( "mgpsnd.p4", 0x180000, 0x080000, CRC(d74b4b03) SHA1(a35c99040a72485a6c2d4a4fdfc203634f6a9ad0) )
ROM_END








ROM_START( m4spotln )
	ROM_REGION( 0x20000, "maincpu", 0 )
	ROM_LOAD( "gsp01.p1", 0x0000, 0x020000, CRC(54c56a07) SHA1(27f21872a7ffe0c497983fa5bbb59e967bf48974) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
ROM_END






ROM_START( m4vivan )
	ROM_REGION( 0x40000, "maincpu", 0 )
	ROM_LOAD( "vlv.bin", 0x0000, 0x010000, CRC(f20c4858) SHA1(94bf19cfa79a1f5347ab61a80cbbce06942187a2) )

	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 )
	ROM_LOAD( "vlvsound1.bin", 0x0000, 0x080000, CRC(ce4da47a) SHA1(7407f8053ee482db4d8d0732fdd7229aa531b405) )
	ROM_LOAD( "vlvsound2.bin", 0x0000, 0x080000, CRC(571c00d1) SHA1(5e7be40d3caae88dc3a580415f8ab796f6efd67f) )
ROM_END







ROM_START( m4sunseta )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "b2512s.p1", 0x0000, 0x010000, CRC(8c509538) SHA1(eab6a1e44e77cb48cf490616facc74932acc93c5) )
	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "sunsetb.chr", 0x0000, 0x000048, CRC(f166963b) SHA1(5cc6ada61036d8dbeca470e9548f9f5d2bd545a8) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4sunsetb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "b2512y.p1", 0x0000, 0x010000, CRC(65fa2cd9) SHA1(d2ab1ae25d5425a0788f86535a20d3ebe4a9db2b) )
	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "sunsetb.chr", 0x0000, 0x000048, CRC(f166963b) SHA1(5cc6ada61036d8dbeca470e9548f9f5d2bd545a8) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4sunsetc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "sunboul-5p3.bin", 0x0000, 0x010000, CRC(5ccbf062) SHA1(cf587018511d1a06624d271f2fde4e40f16ec87c) )
	ROM_REGION( 0x48, "fakechr", 0 )
	ROM_LOAD( "sunsetb.chr", 0x0000, 0x000048, CRC(f166963b) SHA1(5cc6ada61036d8dbeca470e9548f9f5d2bd545a8) )
	ROM_REGION( 0x100000, "msm6376", ROMREGION_ERASE00 )
ROM_END

ROM_START( m4funh )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "funhouse.bin", 0x00000, 0x10000, CRC(4e342025) SHA1(288125ff5e3da7249d89dfcc3cd0915f791f7d43) )
	ROM_REGION( 0x200000, "msm6376", ROMREGION_ERASE00 ) // no idea if it uses an OKI
ROM_END


/* Barcrest */
GAME( 198?, m4tst,        0, mod2    ,   mpu4, mpu4_state,       m4tst,   ROT0, "Barcrest","MPU4 Unit Test (Program 4)",GAME_MECHANICAL )
GAME( 198?, m4tst2,       0, mod2    ,   mpu4, mpu4_state,       m4tst2,  ROT0, "Barcrest","MPU4 Unit Test (Program 2)",GAME_MECHANICAL )
GAME( 198?, m4clr,        0, mod2    ,   mpu4, driver_device,       0,       ROT0, "Barcrest","MPU4 Meter Clear ROM",GAME_MECHANICAL )

#define GAME_FLAGS (GAME_NOT_WORKING|GAME_REQUIRES_ARTWORK)




// other issues
GAME(199?, m4casmul ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Casino Multiplay (Barcrest) (MPU4)",GAME_FLAGS )



// barcrest, to split
GAME(199?, m4c9c    ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Cloud Nine Club (Barcrest) (MPU4) (CNC 2.1)",GAME_FLAGS ) // doesn't boot
GAME(199?, m4ch30   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","unknown MPU4 'CH3 0.1' (Barcrest) (MPU4)",GAME_FLAGS )

// corrupt vfd (bwb?)
GAME(199?, m4clbx   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Club X (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4clbxa  ,m4clbx     ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Club X (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4clbxb  ,m4clbx     ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Club X (Barcrest) (MPU4) (set 3)",GAME_FLAGS )

GAME(199?, m4ringfr ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Ring Of Fire (Barcrest) (MPU4)",GAME_FLAGS )
GAME(199?, m4royjwl ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Royal Jewels (Barcrest) (MPU4)",GAME_FLAGS )

// play but behavior isn't like barcrest
GAME(199?, m4crjwl  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Crown Jewels Club (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4crjwla ,m4crjwl    ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Crown Jewels Club (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4crjwlb ,m4crjwl    ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Crown Jewels Club (Barcrest) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4crjwlc ,m4crjwl    ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Crown Jewels Club (Barcrest) (MPU4) (set 4)",GAME_FLAGS )

GAME(199?, m4crjwl2 ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Crown Jewels Mk II Club (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4crjwl2a,m4crjwl2   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Crown Jewels Mk II Club (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4crjwl2b,m4crjwl2   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Crown Jewels Mk II Club (Barcrest) (MPU4) (set 3)",GAME_FLAGS )

GAME(199?, m4supbjc ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Super Blackjack Club (Barcrest) (MPU4) (set 1)",GAME_FLAGS ) // set stake
GAME(199?, m4supbjca,m4supbjc   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Super Blackjack Club (Barcrest) (MPU4) (set 2)",GAME_FLAGS ) // set stake
GAME(199?, m4supbjcb,m4supbjc   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Super Blackjack Club (Barcrest) (MPU4) (set 3)",GAME_FLAGS ) // set stake
GAME(199?, m4supbjcc,m4supbjc   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Super Blackjack Club (Barcrest) (MPU4) (set 4)",GAME_FLAGS ) // set stake
GAME(199?, m4supbjcd,m4supbjc   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Super Blackjack Club (Barcrest) (MPU4) (set 5)",GAME_FLAGS ) // set stake



// corrupt VFD (many XX)
GAME(199?, m4luckwb     ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Wild Boar (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4luckwba    ,m4luckwb   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Wild Boar (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4luckwbb    ,m4luckwb   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Wild Boar (Barcrest) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4luckwbc    ,m4luckwb   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Wild Boar (Barcrest) (MPU4) (set 4)",GAME_FLAGS )
GAME(199?, m4luckwbd    ,m4luckwb   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Wild Boar (Barcrest) (MPU4) (set 5)",GAME_FLAGS )
GAME(199?, m4luckwbe    ,m4luckwb   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Wild Boar (Barcrest) (MPU4) (set 6)",GAME_FLAGS )
GAME(199?, m4luckwbf    ,m4luckwb   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Wild Boar (Barcrest) (MPU4) (set 7)",GAME_FLAGS )


// won't boot with current reel setup, not even in test mode
GAME(199?, m4maglin ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Magic Liner (Barcrest) (MPU4) (DMA2.1)",GAME_FLAGS )
GAME(199?, m4magdrg ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Magic Dragon (Barcrest) (MPU4) (DMD1.0)",GAME_FLAGS )
GAME(199?, m4clbveg ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Club Vegas (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4clbvega,m4clbveg   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Club Vegas (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4clbvegb,m4clbveg   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Club Vegas (Barcrest) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4clbvegc,m4clbveg   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Club Vegas (Barcrest) (MPU4) (set 4)",GAME_FLAGS )
GAME(199?, m4chasei ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Chase Invaders (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4chaseia,m4chasei   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Chase Invaders (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4chaseib,m4chasei   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Chase Invaders (Barcrest) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4chaseic,m4chasei   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Chase Invaders (Barcrest) (MPU4) (set 4)",GAME_FLAGS )
GAME(199?, m4chaseid,m4chasei   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Chase Invaders (Barcrest) (MPU4) (set 5)",GAME_FLAGS )
GAME(199?, m4chaseie,m4chasei   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Chase Invaders (Barcrest) (MPU4) (set 6)",GAME_FLAGS )
GAME(199?, m4chaseif,m4chasei   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Chase Invaders (Barcrest) (MPU4) (set 7)",GAME_FLAGS )

GAME(199?, m4bluedm ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Blue Diamond (Barcrest) (MPU4) (DBD1.0)",GAME_FLAGS )
GAME(199?, m4amhiwy ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","American Highway (Barcrest) (MPU4) (DAH)",GAME_FLAGS )
GAME(199?, m4addrd  ,m4addr     ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Adders & Ladders (Barcrest) (DAL, Dutch) (MPU4)",GAME_FLAGS )
GAME(199?, m4nudshf ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Nudge Shuffle (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4nudshfa,m4nudshf   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Nudge Shuffle (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4nudshfb,m4nudshf   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Nudge Shuffle (Barcrest) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4nudshfc,m4nudshf   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Nudge Shuffle (Barcrest) (MPU4) (set 4)",GAME_FLAGS )

GAME(199?, m4prem   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Premier (Barcrest) (MPU4) (DPM)",GAME_FLAGS )
GAME(199?, m4rdht   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Red Heat (Golden Nugget?) (Barcrest) (MPU4) (DRH 1.2)",GAME_FLAGS )
GAME(199?, m4rwb    ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Red White & Blue (Barcrest) (MPU4) (DRW)",GAME_FLAGS )
GAME(199?, m4salsa  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Salsa (Barcrest) (MPU4) (DSA)",GAME_FLAGS )
GAME(199?, m4techno ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Techno Reel (Barcrest) (MPU4) (DTE) (set 1)",GAME_FLAGS )
GAME(199?, m4technoa,m4techno   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Techno Reel (Barcrest) (MPU4) (DTE) (set 2)",GAME_FLAGS )
GAME(199?, m4twintm ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Twin Timer (Barcrest) (MPU4) (D2T 1.1)",GAME_FLAGS )
GAME(199?, m4blkbul ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Super Play (Black Bull?) (Czech) (Barcrest) [XSP] (MPU4)",GAME_FLAGS ) // complains about coin dip
GAME(199?, m4calicl ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","California Club (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4calicla,m4calicl   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","California Club (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4caliclb,m4calicl   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","California Club (Barcrest) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4caliclc,m4calicl   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","California Club (Barcrest) (MPU4) (set 4)",GAME_FLAGS )
GAME(199?, m4calicld,m4calicl   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","California Club (Barcrest) (MPU4) (set 5)",GAME_FLAGS )

GAME(199?, m4bucks  ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Bucks Fizz Club (Barcrest) (MPU4)",GAME_FLAGS )

GAME(199?, m4gldgat ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Golden Gate (Barcrest) [DGG, Dutch] (MPU4)",GAME_FLAGS )
GAME(199?, m4hirise ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","High Rise (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4hirisea,m4hirise   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","High Rise (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4hiriseb,m4hirise   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","High Rise (Barcrest) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4hirisec,m4hirise   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","High Rise (Barcrest) (MPU4) (set 4)",GAME_FLAGS )
GAME(199?, m4hirised,m4hirise   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","High Rise (Barcrest) (MPU4) (set 5)",GAME_FLAGS )
GAME(199?, m4hirisee,m4hirise   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","High Rise (Barcrest) (MPU4) (set 6)",GAME_FLAGS )

GAME(199?, m4nspot  ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Night Spot Club (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4nspota ,m4nspot    ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Night Spot Club (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4nspotb ,m4nspot    ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Night Spot Club (Barcrest) (MPU4) (set 3)",GAME_FLAGS )

GAME(199?, m4supbf  ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Super Bucks Fizz Club (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4supbfa ,m4supbf    ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Super Bucks Fizz Club (Barcrest) (MPU4) (set 2)",GAME_FLAGS )

GAME(199?, m4toma   ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Tomahawk (Barcrest) (MPU4)",GAME_FLAGS )
GAME(199?, m4tropcl ,0          ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Tropicana Club (Barcrest) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4tropcla,m4tropcl   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Tropicana Club (Barcrest) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4tropclb,m4tropcl   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Tropicana Club (Barcrest) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4tropclc,m4tropcl   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Tropicana Club (Barcrest) (MPU4) (set 4)",GAME_FLAGS )
GAME(199?, m4tropcld,m4tropcl   ,mod2       ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Tropicana Club (Barcrest) (MPU4) (set 5)",GAME_FLAGS )


// these all seem quite close to Old Timer (unsurprising, many are called XX timer), the 'altreels' is just the same as the oldtimer init, but with the 'guess' CHR emulation
GAME(199?, m4holdtm ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Hold Timer (Barcrest) (Dutch) (MPU4) (DHT)",GAME_FLAGS )
GAME(199?, m4exgam  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Extra Game (Fairplay - Barcrest) (MPU4)",GAME_FLAGS )
GAME(199?, m4brook  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Brooklyn (Barcrest) (MPU4) (PFT 1.8)",GAME_FLAGS )
GAME(199?, m4roadrn ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Road Runner (Barcrest) (Dutch) (MPU4) (DRO1.9)",GAME_FLAGS )
GAME(199?, m4showtm ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Show Timer (Barcrest) (Dutch) (MPU4) (DSH1.3)",GAME_FLAGS )
GAME(199?, m4steptm ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Step Timer (Barcrest) (Dutch) (MPU4) (DST 1.1)",GAME_FLAGS )
GAME(199?, m4toptim ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Top Timer (Barcrest) (Dutch) (MPU4) (DTT) (set 1)",GAME_FLAGS )
GAME(199?, m4toptima,m4toptim   ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Top Timer (Barcrest) (Dutch) (MPU4) (DTT) (set 2)",GAME_FLAGS )

GAME(199?, m4univ   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Universe (Barcrest) (Dutch) (MPU4) (DUN)",GAME_FLAGS )
GAME(199?, m4wildtm ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Wild Timer (Barcrest) (Dutch) (MPU4) (DWT 1.3)",GAME_FLAGS )


GAME(199?, m4frtgm  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Fruit Game (Barcrest) (MPU4)",GAME_FLAGS ) // SAMPLE EEPROM ALARM (and has a weird sample rom..)
GAME(199?, m4reeltm ,0          ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Reel Timer (Barcrest) (MPU4) (DWT)",GAME_FLAGS ) // SAMPLE EEPROM ALARM
GAME(199?, m4fortcb     ,0                  ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Fortune Club (Barcrest) (MPU4) (set 1)",GAME_FLAGS ) // INVALID ALARM
GAME(199?, m4fortcba    ,m4fortcb           ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Fortune Club (Barcrest) (MPU4) (set 2)",GAME_FLAGS ) // INVALID ALARM
GAME(199?, m4fortcbb    ,m4fortcb           ,mod4oki    ,mpu4               , mpu4_state,m4altreels         ,ROT0,   "Barcrest","Fortune Club (Barcrest) (MPU4) (set 3)",GAME_FLAGS ) // INVALID ALARM



// GEEN TUBES (even in test mode)
GAME(199?, m4topdk  ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Top Deck (Barcrest) (Dutch) (MPU4)",GAME_FLAGS )

// non-english sets
GAME(199?, m4magrep ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Magic Replay (Barcrest) (Dutch) (MPU4)",GAME_FLAGS )
GAME(199?, m4nile   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Nile Jewels (Barcrest) (German) (MPU4) (GJN0.8)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4jokmil ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Jokers Millennium (Barcrest) (German) (MPU4)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4drac   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Dracula (Barcrest - Nova) (German) (MPU4) (set 1)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4draca  ,m4drac     ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Dracula (Barcrest - Nova) (German) (MPU4) (set 2)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4dracb  ,m4drac     ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Dracula (Barcrest - Nova) (German) (MPU4) (set 3)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwl ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 1)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwla,m4crzjwl   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 2)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwlb,m4crzjwl   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 3)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwlc,m4crzjwl   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 4)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwld,m4crzjwl   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 5)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwle,m4crzjwl   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 6)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwlf,m4crzjwl   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 7)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwlg,m4crzjwl   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 8)",GAME_FLAGS ) // DM1 SW ALM
GAME(199?, m4crzjwlh,m4crzjwl   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Crown Jewels (Barcrest) (German) (MPU4) (set 9)",GAME_FLAGS ) // DM1 SW ALM

GAME(199?, m4vegastg,m4vegast   ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Vegas Strip (Barcrest) [German] (MPU4)",GAME_FLAGS ) // 1 DM SW ALM
GAME(199?, m4jok300 ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Jokers 300 (Barcrest) (German?) (MPU4)",GAME_FLAGS ) // also contains crystal maze stuff??
GAME(199?, m4luckdv ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Devil (Barcrest) [Czech] (MPU4)",GAME_FLAGS ) // AUX2 locked
GAME(199?, m4luckdvd,m4luckdv   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky Devil (Barcrest) [Dutch] (MPU4) (DLD)",GAME_FLAGS )
GAME(199?, m4luck7  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Lucky 7 (Barcrest) (Dutch) (MPU4)",GAME_FLAGS ) // '1,2' error
GAME(199?, m4joljokh,m4joljok   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Jolly Joker (Barcrest) [Hungarian] (MPU4) (HJJ)",GAME_FLAGS )
GAME(199?, m4hpyjok ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Happy Joker (Barcrest) (Dutch) (MPU4) (DHJ1.2)",GAME_FLAGS )
GAME(199?, m4gldjok ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Golden Joker (Barcrest) (Dutch) (MPU4) (DGJ 1.2)",GAME_FLAGS )
GAME(199?, m4ceptr  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Ceptor (Barcrest) (Dutch) (MPU4) (DCE 1.0)",GAME_FLAGS )
GAME(199?, m4blkcat ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Black Cat (Barcrest) (Dutch) (MPU4) (DBL 1.4)",GAME_FLAGS )
GAME(199?, m4gnsmk  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Gun Smoke (Barcrest) (Dutch) (MPU4)",GAME_FLAGS )
GAME(199?, m4blkbuld,m4blkbul   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Gun Smoke (Barcrest) (Dutch, alt sound roms) (MPU4)",GAME_FLAGS ) // not sure either set of sound roms is right
GAME(199?, m4blkwhd ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Black & White (Barcrest) [Dutch] (MPU4) (DBW 1.1)",GAME_FLAGS )
GAME(199?, m4oldtmr ,0          ,mod4oki    ,mpu4               , mpu4_state,m_oldtmr           ,ROT0,   "Barcrest","Old Timer (Barcrest) (Dutch) (MPU4) (DOT1.1)",GAME_FLAGS )
GAME(199?, m4casot  ,m4oldtmr   ,mod4oki    ,mpu4               , mpu4_state,m_oldtmr           ,ROT0,   "Barcrest","Old Timer (Barcrest) (Dutch, alt 'Black and White' sound roms) (DOT1.1)",GAME_FLAGS ) // uses the same program???
GAME(199?, m4jpmcla ,m4oldtmr   ,mod4oki    ,mpu4               , mpu4_state,m_oldtmr           ,ROT0,   "Barcrest","Old Timer (Barcrest) (Dutch, alt 'JPM Classic' sound roms) (DOT1.1)",GAME_FLAGS ) // uses the same program???
GAME(199?, m4tbplay ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Turbo Play (Barcrest) (Dutch) (MPU4) (DTP) (set 1)",GAME_FLAGS )
GAME(199?, m4tbplaya,m4tbplay   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Turbo Play (Barcrest) (Dutch) (MPU4) (DTP) (set 2)",GAME_FLAGS )
GAME(199?, m4tbplayb,m4tbplay   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Turbo Play (Barcrest) (Dutch) (MPU4) (DTP) (set 3)",GAME_FLAGS )

GAME(199?, m4vivalvd,m4vivalv   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Viva Las Vegas (Barcrest) [Dutch] (MPU4) (DLV)",GAME_FLAGS )

GAME(199?, m4toprn  ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Top Run (Barcrest) (Dutch) (MPU4)",GAME_FLAGS ) // unique behavior  (START UP IN countdown)

GAME(199?, m4magtbo ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Magic Turbo  (Barcrest) (MPU4)",GAME_FLAGS )

// bwb/nova?
GAME(199?, m4ordmnd ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Oriental Diamonds (Barcrest) (German) (MPU4)",GAME_FLAGS )
// ?
GAME(199?, m4ptblkc ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Pot Black Casino (Bwb - Barcrest) (MPU4)",GAME_FLAGS ) // main cpu crashes?


// badchr
GAME(199?, m4take5  ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Barcrest","Take 5 (Barcrest) (MPU4)",GAME_FLAGS )

// REEL 1 FAULT
GAME(199?, m4twist  ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Twist Again (Barcrest) (MPU4) (set 1)",GAME_FLAGS ) // TA 9.6  REEL 1 FAULT
GAME(199?, m4twista ,m4twist    ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Twist Again (Barcrest) (MPU4) (set 2)",GAME_FLAGS ) // TA 9.6  REEL 1 FAULT
GAME(199?, m4twistb ,m4twist    ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Twist Again (Barcrest) (MPU4) (set 3)",GAME_FLAGS ) // TA 9.6  REEL 1 FAULT



// might need samples, but run silent with none
GAME(199?, m4lineup     ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Line Up (Bwb - Barcrest) (MPU4) (set 1)",GAME_FLAGS ) // no sound with any system?
GAME(199?, m4lineupa    ,m4lineup   ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Line Up (Bwb - Barcrest) (MPU4) (set 2)",GAME_FLAGS ) // no sound with any system?

GAME(199?, m4czne   ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Cash Zone (Bwb) (MPU4)",GAME_FLAGS )
GAME(199?, m4fourmr ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Four More (Bwb) (MPU4)",GAME_FLAGS ) // no sound with either system?
GAME(199?, m4holywd ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Hollywood (Bwb) (MPU4)",GAME_FLAGS )
GAME(199?, m4specu  ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Speculator Club (Bwb) (MPU4)",GAME_FLAGS ) // no sound with either system


GAME(199?, m4lazy   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Bwb","Lazy Bones (Bwb) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4lazya  ,m4lazy     ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Bwb","Lazy Bones (Bwb) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4lazyb  ,m4lazy     ,mod4oki    ,mpu4               , mpu4_state,m4default_big  ,ROT0,   "Bwb","Lazy Bones (Bwb) (MPU4) (set 3)",GAME_FLAGS )

GAME(199?, m4sunclb ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Sun Club (Bwb) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4sunclba,m4sunclb   ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Sun Club (Bwb) (MPU4) (set 2)",GAME_FLAGS )

GAME(199?, m4sunscl ,0          ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Sunset Club (Bwb) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4sunscla,m4sunscl   ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Sunset Club (Bwb) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4sunsclb,m4sunscl   ,mod2       ,mpu4               , mpu4_state,m4default          ,ROT0,   "Bwb","Sunset Club (Bwb) (MPU4) (set 3)",GAME_FLAGS )

GAME(199?, m4bigban ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Nova","Big Bandit (Nova) (MPU4)",GAME_FLAGS )
GAME(199?, m4crzcsn ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Nova","Crazy Casino (Nova) (MPU4)",GAME_FLAGS )
GAME(199?, m4crzcav ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Nova","Crazy Cavern (Nova) (MPU4)",GAME_FLAGS )
GAME(199?, m4dragon ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Nova","Dragon (Nova) (MPU4)",GAME_FLAGS )
GAME(199?, m4hilonv ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Nova","Hi Lo Casino (Nova) (MPU4)",GAME_FLAGS )
GAME(199?, m4octo   ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Nova","Octopus (Nova) (MPU4)",GAME_FLAGS )
GAME(199?, m4sctagt ,0          ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Nova","Secret Agent (Nova) (MPU4)",GAME_FLAGS )



/* Others */


GAME(199?, m4aao,     0,        mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Eurotek","Against All Odds (Eurotek) (MPU4)",GAME_FLAGS )
GAME(199?, m4bandgd,  0,        mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Eurogames","Bands Of Gold (Eurogames) (MPU4)",GAME_FLAGS )

GAME(199?, m4bigben,  0,        mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Big Ben (Coinworld) (MPU4, set 1)",GAME_FLAGS )
GAME(199?, m4bigbena, m4bigben, mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Big Ben (Coinworld) (MPU4, set 2)",GAME_FLAGS )
GAME(199?, m4bigbenb, m4bigben, mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Big Ben (Coinworld) (MPU4, set 3)",GAME_FLAGS )
GAME(199?, m4bigbend, m4bigben, mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Big Ben (Coinworld) (MPU4, set 4)",GAME_FLAGS )
GAME(199?, m4bigbene, m4bigben, mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Big Ben (Coinworld) (MPU4, set 5)",GAME_FLAGS )
GAME(199?, m4kqclub,  0,        mod2    ,mpu4, mpu4_state, m4default, ROT0,   "Newby","Kings & Queens Club (Newby) (MPU4)",GAME_FLAGS )
GAME(199?, m4snookr,  0,        mod2    ,mpu4, mpu4_state, m4default, ROT0,   "Eurocoin","Snooker (Eurocoin) (MPU4)",GAME_FLAGS ) // works?
GAME(199?, m4stakex,  0,        mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Leisurama","Stake X (Leisurama) (MPU4, set 1)",GAME_FLAGS ) // has issues with coins in 'separate bank' (default) mode, reel issues
GAME(199?, m4stakexa, m4stakex, mod4oki, mpu4, mpu4_state, m4default, ROT0,   "Leisurama","Stake X (Leisurama) (MPU4, set 2)",GAME_FLAGS ) // like above, but doesn't default to separate bank?
GAME(199?, m4boltbl,  0,        mod2    ,mpu4, mpu4_state, m4default, ROT0,   "DJE","Bolt From The Blue (DJE) (MPU4, set 1)",GAME_FLAGS ) // Reel 1 Fault
GAME(199?, m4boltbla, m4boltbl, mod2    ,mpu4, mpu4_state, m4default, ROT0,   "DJE","Bolt From The Blue (DJE) (MPU4, set 2)",GAME_FLAGS )
GAME(199?, m4boltblb, m4boltbl, mod2    ,mpu4, mpu4_state, m4default, ROT0,   "DJE","Bolt From The Blue (DJE) (MPU4, set 3)",GAME_FLAGS )
GAME(199?, m4boltblc, m4boltbl, mod2    ,mpu4, mpu4_state, m4default, ROT0,   "DJE","Bolt From The Blue (DJE) (MPU4, set 4)",GAME_FLAGS )
GAME(199?, m4stand2,  0,        mod2    ,mpu4, mpu4_state, m4default, ROT0,   "DJE","Stand To Deliver (DJE) (MPU4)",GAME_FLAGS ) // Reel 1 Fault
GAME(199?, m4dblchn,  0,        mod4oki, mpu4, mpu4_state, m4default, ROT0,   "DJE","Double Chance (DJE) (MPU4)",GAME_FLAGS ) // Reels spin forever

/* Unknown stuff that looks like it might be MPU4, but needs further verification, some could be bad */

GAME(199?, m4barcrz ,  0,       mod4oki ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Bar Crazy (unknown) (MPU4?)",GAME_FLAGS )
GAME(199?, m4bonzbn ,  0,       mod4oki ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Bingo Bonanza (unknown) (MPU4?)",GAME_FLAGS )
GAME(199?, m4cld02  ,  0,       mod4oki ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'CLD 0.2C' (MPU4?)",GAME_FLAGS )
GAME(199?, m4matdr  ,  0,       mod4oki ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Matador (unknown) (MPU4?)",GAME_FLAGS )
GAME(199?, m4hslo   ,  0,       mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'HOT 3.0' (MPU4?)",GAME_FLAGS )
GAME(199?, m4unkjok ,  0,       mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'Joker' (MPU4?) (set 1)",GAME_FLAGS ) // bad chr
GAME(199?, m4unkjoka,  m4unkjok,mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'Joker' (MPU4?) (set 2)",GAME_FLAGS ) // bad chr
GAME(199?, m4unkjokb,  m4unkjok,mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'Joker' (MPU4?) (set 3)",GAME_FLAGS ) // bad chr
GAME(199?, m4unkjokc,  m4unkjok,mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'Joker' (MPU4?) (set 4)",GAME_FLAGS ) // bad chr
GAME(199?, m4remag  ,  0,       mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'ZTP 0.7' (MPU4?)",GAME_FLAGS )
GAME(199?, m4rmg    ,  0,       mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'CTP 0.4' (MPU4?)",GAME_FLAGS )
GAME(199?, m4wnud   ,  0,       mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'W Nudge' (MPU4?)",GAME_FLAGS )
GAME(199?, m4t266   ,  0,       mod2    ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","unknown MPU4 'TTO 1.1' (MPU4?)",GAME_FLAGS )
GAME(199?, m4brnze  ,  0,       mod4oki, mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Bronze Voyage (unknown) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4brnzea ,  m4brnze, mod4oki, mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Bronze Voyage (unknown) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4brnzeb ,  m4brnze, mod4oki, mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Bronze Voyage (unknown) (MPU4) (set 3)",GAME_FLAGS )

GAME(199?, m4riotrp ,  0,       mod4oki, mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Rio Tropico (unknown) (MPU4)",GAME_FLAGS )

/* *if* these are MPU4 they have a different sound system at least - The copyright strings in them are 'AET' tho (Ace?) - Could be related to the Crystal stuff? */
GAME(199?, m4sbx    ,  0,       mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Super Bear X (MPU4?) (set 1)",GAME_FLAGS )
GAME(199?, m4sbxa   ,  m4sbx,   mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Super Bear X (MPU4?) (set 2)",GAME_FLAGS )
GAME(199?, m4sbxb   ,  m4sbx,   mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Super Bear X (MPU4?) (set 3)",GAME_FLAGS )
GAME(199?, m4sbxc   ,  m4sbx,   mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Super Bear X (MPU4?) (set 4)",GAME_FLAGS )
GAME(199?, m4sbxd   ,  m4sbx,   mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Super Bear X (MPU4?) (set 5)",GAME_FLAGS )
GAME(199?, m4sbxe   ,  m4sbx,   mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Super Bear X (MPU4?) (set 6)",GAME_FLAGS )

GAME(199?, m4bclimb ,  0,       mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Bear Climber (MPU4?)",GAME_FLAGS )
GAME(199?, m4captb  ,  0,       mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Captain Bear (MPU4?)",GAME_FLAGS )
GAME(199?, m4jungj  ,  0,       mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Jungle Japes (MPU4?) (set 1)",GAME_FLAGS )
GAME(199?, m4jungja ,  m4jungj, mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Jungle Japes (MPU4?) (set 2)",GAME_FLAGS )
GAME(199?, m4jungjb ,  m4jungj, mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Jungle Japes (MPU4?) (set 3)",GAME_FLAGS )
GAME(199?, m4jungjc ,  m4jungj, mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Jungle Japes (MPU4?) (set 4)",GAME_FLAGS )

GAME(199?, m4fsx    ,  0,       mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Fun Spot X (MPU4?) (set 1)",GAME_FLAGS )
GAME(199?, m4fsxa   ,  m4fsx,   mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Fun Spot X (MPU4?) (set 2)",GAME_FLAGS )
GAME(199?, m4fsxb   ,  m4fsx,   mpu4crys    ,mpu4, mpu4_state, m_frkstn, ROT0,   "AET/Coinworld","Fun Spot X (MPU4?) (set 3)",GAME_FLAGS )

GAME(199?, m4ccop   ,  0,       mod4oki     ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Cash Cops (MPU4?) (set 1)",GAME_FLAGS )
GAME(199?, m4ccopa  ,  m4ccop,  mod4oki     ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Cash Cops (MPU4?) (set 2)",GAME_FLAGS )
GAME(199?, m4ccopb  ,  m4ccop,  mod4oki     ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Cash Cops (MPU4?) (set 3)",GAME_FLAGS )

GAME(199?, m4ccc    ,  0,       mod4oki     ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Criss Cross Crazy (Coinworld) (MPU4?)",GAME_FLAGS )
GAME(199?, m4treel  ,  0,       mod2        ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Turbo Reels (unknown) (MPU4?) (set 1)",GAME_FLAGS )
GAME(199?, m4treela ,  m4treel, mod2        ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Turbo Reels (unknown) (MPU4?) (set 2)",GAME_FLAGS )




GAME(199?, m4surf, 0,           mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Gemini","Super Surfin' (Gemini) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4surfa,m4surf,      mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Gemini","Super Surfin' (Gemini) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4surfb,m4surf,      mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Gemini","Super Surfin' (Gemini) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4wife, 0,           mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Gemini","Money Or Yer Wife (Gemini) (MPU4)",GAME_FLAGS )
GAME(199?, m4blkgd, 0,          mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Gemini","Black Gold (Gemini) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4blkgda,m4blkgd,    mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Gemini","Black Gold (Gemini) (MPU4) (set 2)",GAME_FLAGS )

GAME(199?, m4zill, 0,           mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Pure Leisure","Zillionare's Challenge (Pure Leisure) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4zilla, m4zill,     mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Pure Leisure","Zillionare's Challenge (Pure Leisure) (MPU4) (set 2)",GAME_FLAGS )

GAME(199?, m4hstr, 0,           mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Happy Streak (Coinworld) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4hstra,m4hstr,      mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Happy Streak (Coinworld) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4hstrb,m4hstr,      mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Happy Streak (Coinworld) (MPU4) (set 3)",GAME_FLAGS )

GAME(199?, m4hstrcs, 0,         mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Casino Happy Streak (Coinworld) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4hstrcsa,m4hstrcs,  mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Casino Happy Streak (Coinworld) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4hstrcsb,m4hstrcs,  mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Casino Happy Streak (Coinworld) (MPU4) (set 3)",GAME_FLAGS )
GAME(199?, m4hstrcsc,m4hstrcs,  mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Casino Happy Streak (Coinworld) (MPU4) (set 4)",GAME_FLAGS )
GAME(199?, m4hstrcsd,m4hstrcs,  mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Casino Happy Streak (Coinworld) (MPU4) (set 5)",GAME_FLAGS )

GAME(199?, m4ddb,  0,           mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Ding Dong Bells (Coinworld) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4ddba, m4ddb,       mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Ding Dong Bells (Coinworld) (MPU4) (set 2)",GAME_FLAGS )

GAME(199?, m4hapfrt,  0,            mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Happy Fruits (Coinworld) (MPU4) (set 1)",GAME_FLAGS )
GAME(199?, m4hapfrta, m4hapfrt,     mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Happy Fruits (Coinworld) (MPU4) (set 2)",GAME_FLAGS )
GAME(199?, m4hapfrtb, m4hapfrt,     mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Coinworld","Happy Fruits (Coinworld) (MPU4) (set 3)",GAME_FLAGS )


GAME(199?, m4sunday, 0,         mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Pcp","Sunday Sport (Pcp) (MPU4)",GAME_FLAGS )

GAME(199?, m4jp777, 0,          mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Cotswold Microsystems","Jackpot 777 (Cotswold Microsystems) (MPU4)",GAME_FLAGS ) /* Hopper Fault */
GAME(199?, m4dnj    ,  0,       mod4oki ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Double Nudge (unknown) (MPU4) (set 1)",GAME_FLAGS ) /* Hopper Fault */
GAME(199?, m4dnja   ,  m4dnj,   mod4oki ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Double Nudge (unknown) (MPU4) (set 2)",GAME_FLAGS ) /* Hopper Fault */
GAME(199?, m4dnjb   ,  m4dnj,   mod4oki ,mpu4, mpu4_state, m4default, ROT0,   "<unknown>","Double Nudge (unknown) (MPU4) (set 3)",GAME_FLAGS ) /* Hopper Fault */

GAME(199?, m4booze, 0,          mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Extreme","Booze Cruise (Extreme) (MPU4)",GAME_FLAGS )
GAME(199?, m4cbing, 0,          mod4oki    ,mpu4, mpu4_state, m4default, ROT0,   "Redpoint Systems","Cherry Bingo (Redpoint Systems) (MPU4)",GAME_FLAGS ) // custom sound system


GAME( 199?, m4nod       , 0         ,  mod4oki      , mpu4      , mpu4_state, m4default     , 0,         "Eurotech",   "Nod And A Wink (Eurotech) (MPU4)",GAME_FLAGS|GAME_MECHANICAL|GAME_SUPPORTS_SAVE) // this has valid strings in it BEFORE the bfm decode, but decodes to valid code, does it use some funky mapping, or did they just fill unused space with valid looking data?


// not sure about several of the nova ones
GAME( 199?, m4aliz      , 0         ,  mod4oki      , mpu4      , mpu4_state, m4default     , 0,         "Qps",  "AlizBaz (Qps) (German) (MPU4)",GAME_FLAGS|GAME_MECHANICAL|GAME_SUPPORTS_SAVE)
GAME( 199?, m4coney     , 0         ,  mod4oki      , mpu4      , mpu4_state, m4default     , 0,         "Qps",   "Coney Island (Qps) (MPU4)",GAME_FLAGS|GAME_MECHANICAL|GAME_SUPPORTS_SAVE)
GAME( 199?, m4crzjk     , 0         ,  mod2         , mpu4      , mpu4_state, m4default     , 0,         "Nova?", "Crazy Jokers (Nova?) (MPU4)",GAME_FLAGS )  // COIN   ALM
GAME( 199?, m4c2        , 0         ,  mod4oki      , mpu4      , mpu4_state, m4default     , 0,         "Nova?", "Circus Circus 2 (Nova?) (MPU4)",GAME_FLAGS|GAME_MECHANICAL|GAME_SUPPORTS_SAVE) // COIN   ALM
// regular barcrest structure
GAME( 199?, m4vivan     , 0         ,  mod4oki      , mpu4      , mpu4_state, m4default     , 0,         "Nova",  "Viva Las Vegas (Nova) (MPU4)",GAME_FLAGS|GAME_MECHANICAL|GAME_SUPPORTS_SAVE)
GAME( 199?, m4spotln    , 0         ,  mod4oki      , mpu4      , mpu4_state, m4default     , 0,         "Nova",  "Spotlight (Nova) (MPU4)",GAME_FLAGS|GAME_MECHANICAL|GAME_SUPPORTS_SAVE)
GAME( 199?, m4mgpn      , 0         ,  mod4oki      , mpu4      , mpu4_state, m4default     , 0,         "Nova",  "Monaco Grand Prix (Nova) (MPU4)",GAME_FLAGS|GAME_MECHANICAL|GAME_SUPPORTS_SAVE)
GAME( 199?, m4goldnn    , 0         ,  mod4oki      , mpu4      , mpu4_state, m4default     , 0,         "Nova",  "Golden Years (Nova) (MPU4)",GAME_FLAGS|GAME_MECHANICAL|GAME_SUPPORTS_SAVE)




GAME( 198?, m4funh      , 0         , mod4oki           , mpu4  , mpu4_state, m4default         , 0,       "unknown",      "Fun House (unknown) (MPU4)", GAME_FLAGS ) // TUNE ALARM  (was in the SC1 Fun House set)


GAME(199?, m4sunseta    ,m4sunset   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Sunset Boulevard (Barcrest) (MPU4) (B25 1.2, set 1)",GAME_FLAGS )
GAME(199?, m4sunsetb    ,m4sunset   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Sunset Boulevard (Barcrest) (MPU4) (B25 1.2, set 2)",GAME_FLAGS )
GAME(199?, m4sunsetc    ,m4sunset   ,mod4oki    ,mpu4               , mpu4_state,m4default          ,ROT0,   "Barcrest","Sunset Boulevard (Barcrest) (MPU4) (OSB 0.2)",GAME_FLAGS ) // might be a mod 2
