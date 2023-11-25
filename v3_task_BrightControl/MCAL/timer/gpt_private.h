/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef GPT_PRIVATE_H_
#define GPT_PRIVATE_H_

/********************************************************************************/
/*                              MACROS OF CONFIGURATIONS                       */
/********************************************************************************/
#define CLK_FREQUENCY         16000000.0
#define CONVERT_TO_MICRO      1000000.0
#define CONVERT_TO_MILLI      1000.0
#define ZERO_F                0.0
#define ONE_F                 1.0


/********************************************************************************/
/*                              GPT REGISTERS                                   */
/********************************************************************************/
#define GPT_OFFSET(x)         (x<8?((0x40030000)+((x)*0x1000)):((0x4004C000)+((x-8)*0x1000)))

#define GPTMCFG(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x000)))
#define GPTMTAMR(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x004)))
#define GPTMTBMR(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x008)))
#define GPTMCTL(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x00C)))
#define GPTMSYNC(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x010)))
#define GPTMIMR(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x018)))
#define GPTMRIS(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x01C)))
#define GPTMMIS(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x020)))
#define GPTMICR(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x024)))
#define GPTMTAILR(x)          (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x028)))
#define GPTMTBILR(x)          (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x02C)))
#define GPTMTAMATCHR(x)       (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x030)))
#define GPTMTBMATCHR(x)       (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x034)))
#define GPTMTAPR(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x038)))
#define GPTMTBPR(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x03C)))
#define GPTMTAPMR(x)          (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x040)))
#define GPTMTBPMR(x)          (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x044)))	
#define GPTMTAR(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x048)))
#define GPTMTBR(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x04C)))		
#define GPTMTAV(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x050)))
#define GPTMTBV(x)            (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x054)))		
#define GPTMRTCPD(x)          (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x058)))	
#define GPTMTAPS(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x05C)))	
#define GPTMTBPS(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x060)))	
#define GPTMTAPV(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x064)))
#define GPTMTBPV(x)           (*(volatile uint32_t*)(GPT_OFFSET(x)+(0x068)))
#define GPTMPP(x)             (*(volatile uint32_t*)(GPT_OFFSET(x)+(0xFC0)))	
#define RCGCTIMER             (*(volatile uint32_t*)(0x400FE604))
#define RCGCWTIMER            (*(volatile uint32_t*)(0x400FE65C))
	
/********************************************************************************/
/*                              MACROS OF BITS IN REGISTERS                     */
/********************************************************************************/
#define GPTMCTL_TAEN          (0)
#define GPTMIMR_TATOIM        (0)
#define GPTMRIS_TATORIS       (0)
#define GPTMICR_TATOCINT      (0)
#define GPTMCFG_SINGLE        (0x4)
#define GPTMCFG_DOUBLE        (0x0)
#define ONE_SHOT_VALUE        (0x1)
#define PERIODIC_VALUE        (0x2)


#endif /*GPT_PRIVATE_H_*/
