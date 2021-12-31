

#include "display.h"

display_data_ dDisplayData = {0};
uint64_t disp_time = 0, disp_time_saved = 0;
char stringToDisplay[4] = {0};

void updateDisplay(void);
void setDigit(uint8_t pos);

/*Reset (turn-off) all the segments of display*/
void resetSegments(void)
{
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_11);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_8);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_3);
}

/*Set (turn-on) all the segments of display*/
void setSegments(void)
{
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_11);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_1);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_1);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_3);
}

/* Reset (turn-off) all digits*/
void resetDigits(void)
{
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_2);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_0);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_12);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7);
}

/* Reset (turn-on) all digits*/
void setDigits(void)
{
	DIGIT_1_ON;
	DIGIT_2_ON;
	DIGIT_3_ON;
	DIGIT_4_ON;
	DIGIT_TIME_ON;
}

void setDecimalPoint(void)
{
	LL_GPIO_ResetOutputPin(SEGMENTDP_PORT, SEGMENTDP_PIN);
}

/* Functions to display numbers 0 - 9 */
void setOne(void)
{
	// B,C
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
}

void setTwo(void)
{
	// A,B,G,E,D
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
}

void setThree(void)
{
	// A,B,G,C,D
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
}

void setFour(void)
{
	// F,B,G,C
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
}

void setFive(void)
{
	// A,F,G,C,D
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
}

void setSix(void)
{
	// A,F,G,E,C,D
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
}

void setSeven(void)
{
	// A,B,C
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
}

void setEight(void)
{
	// A,B,C,D,E,F,G
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
}

void setNine(void)
{
	// A,B,C
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
}

void setZero(void)
{
	// A,B,C,D,E,F
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
}

void set_(void){
	// D
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
}

void seta(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setb(void){
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setc(void){
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setd(void){
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setE(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setF(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setG(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
}

void seth(void){
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setI(void){
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
}

void setJ(void){
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
}

void setL(void){
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
}

void setn(void){
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void seto(void){
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setP(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setq(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setr(void){
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setS(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void sett(void){
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setu(void){
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
}

void sety(void){
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setK(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setM(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
}

void setV(void){
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
}

void setW(void){
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN); //C
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN); //F
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setX(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

void setZ(void){
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN); //A
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN); //B
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN); //D
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN); //E
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN); //G
}

/**
 * Pre-process number before it is displayed. Extract digits of the number
 */
void displayNumber(double num)
{
	uint8_t i = 0;

	if(num < 0) return;

	if(num > 9999)
	{
		dDisplayData.digit_num = 4;
		dDisplayData.negative = 0;
		dDisplayData.resolution = 0;
	}
	else if(num >= 1000)
	{
		dDisplayData.digit_num = 4;
		dDisplayData.resolution = 0;

	    while(num > 1)
	    {
	    	dDisplayData.digit[i] = (uint32_t)num % 10;
	        num = num / 10;
	        i++;
	    }
	}
	else if(num >= 100)
	{
		dDisplayData.digit_num = 3;
		dDisplayData.resolution = 1;

		num = num * 10;

	    while(num > 1)
	    {
	    	dDisplayData.digit[i] = (uint32_t)num % 10;
	        num = num / 10;
	        i++;
	    }
	}
	else if(num >= 10)
	{
		dDisplayData.digit_num = 2;
		dDisplayData.resolution = 2;

		num = num * 100;

	    while(num > 1)
	    {
	    	dDisplayData.digit[i] = (uint32_t)num % 10;
	        num = num / 10;
	        i++;
	    }
	}
	else if(num >= 1)
	{
		dDisplayData.digit_num = 1;
		dDisplayData.resolution = 3;

		num = num * 1000;

	    while(num > 1)
	    {
	    	dDisplayData.digit[i] = (uint32_t)num % 10;
	        num = num / 10;
	        i++;
	    }
	}
	else if(num >= 0)
	{
		dDisplayData.digit_num = 1;
		dDisplayData.resolution = 3;

		num = num * 1000;
		dDisplayData.digit[3] = 0;

	    while(num > 1)
	    {
	    	dDisplayData.digit[i] = (uint32_t)num % 10;
	        num = num / 10;
	        i++;
	    }
	}
}

void displayString(char *string){
	for(int i = 0; i < 4; i++){
		stringToDisplay[i] = string[i];
	}
}
/*
 * Turns required digit ON
 */
void setDigit(uint8_t pos)
{
	switch(pos)
	{
		case 0:
			DIGIT_1_ON;
			break;
		case 1:
			DIGIT_2_ON;
			break;
		case 2:
			DIGIT_3_ON;
			break;
		case 3:
			DIGIT_4_ON;
			break;
	}
}

/**
 * Display data in dDisplayData.
 * Sets every digit to display its value and decimal point.
 */
void updateDisplay(void)
{
	for(uint8_t i = 0; i < 4; i++)
	{
		switch(stringToDisplay[i]){
		case 'a': case 'A':
			setDigit(i);
			seta();
			break;
		case 'b': case'B':
			setDigit(i);
			setb();
			break;
		case 'c': case'C':
			setDigit(i);
			setc();
			break;
		case 'd': case'D':
			setDigit(i);
			setd();
			break;
		case 'e': case'E':
			setDigit(i);
			setE();
			break;
		case 'f': case'F':
			setDigit(i);
			setF();
			break;
		case 'g': case'G':
			setDigit(i);
			setG();
			break;
		case 'h': case'H':
			setDigit(i);
			seth();
			break;
		case 'i': case'I':
			setDigit(i);
			setI();
			break;
		case 'j': case'J':
			setDigit(i);
			setJ();
			break;
		case 'k': case'K':
			setDigit(i);
			setK();
			break;
		case 'l': case'L':
			setDigit(i);
			setL();
			break;
		case 'm': case'M':
			setDigit(i);
			setM();
			break;
		case 'n': case'N':
			setDigit(i);
			setn();
			break;
		case 'o': case'O':
			setDigit(i);
			seto();
			break;
		case 'p': case'P':
			setDigit(i);
			setP();
			break;
		case 'q': case'Q':
			setDigit(i);
			setq();
			break;
		case 'r': case'R':
			setDigit(i);
			setr();
			break;
		case 's': case'S':
			setDigit(i);
			setS();
			break;
		case 't': case'T':
			setDigit(i);
			sett();
			break;
		case 'u': case'U':
			setDigit(i);
			setu();
			break;
		case 'v': case'V':
			setDigit(i);
			setV();
			break;
		case 'w': case'W':
			setDigit(i);
			setW();
			break;
		case 'x': case'X':
			setDigit(i);
			setX();
			break;
		case 'y': case'Y':
			setDigit(i);
			sety();
			break;
		case 'z': case'Z':
			setDigit(i);
			setZ();
			break;
		case '0':
			setDigit(i);
			setZero();
			break;
		case '1':
			setDigit(i);
			setOne();
			break;
		case '2':
			setDigit(i);
			setTwo();
			break;
		case '3':
			setDigit(i);
			setThree();
			break;
		case '4':
			setDigit(i);
			setFour();
			break;
		case '5':
			setDigit(i);
			setFive();
			break;
		case '6':
			setDigit(i);
			setSix();
			break;
		case '7':
			setDigit(i);
			setSeven();
			break;
		case '8':
			setDigit(i);
			setEight();
			break;
		case '9':
			setDigit(i);
			setNine();
			break;
		case '_': case '.':
		    setDigit(i);
			set_();
			break;
		}
//
//		if(dDisplayData.resolution == i)
//		{
//			setDecimalPoint();
//		}

		disp_time_saved = disp_time;
		while((disp_time_saved + 2) > disp_time){};

		resetDigits();
		resetSegments();
	}
}

//Update displayed data and keep display ON
void TIM3_IRQHandler(void)
{
	if(LL_TIM_IsActiveFlag_UPDATE(TIM3))
	{
		updateDisplay();
	}

	LL_TIM_ClearFlag_UPDATE(TIM3);
}

