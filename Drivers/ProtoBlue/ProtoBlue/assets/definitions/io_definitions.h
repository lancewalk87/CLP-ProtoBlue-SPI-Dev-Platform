/**
 * io_definitions.h
 * ProtoBlue
 *
 * Created by Lance T. Walker on 10/5/2018 11:04:12 PM.
 * Copyright � 2018 CodeLife-Productions. All rights reserved.
--------------------------------------------------------------------------------------------
 * AVR: [ATmega644P 20AU] I/O:
 * Counters	= Prescaler and Comparator x2
 * PWM Channels	= 6
 * ADC Channels	= 10-bit x8
 * General Purpose I/O = 32
 * Ports = 4
 * Total Pins = 44
--------------------------------------------------------------------------------------------
 * Categorical Prefixes: | Port/Registers: | Pins:
 * SPI = SPI | B = 0x24,0x25| PB4, PB5, PB6, PB7
 * Charger = CHG | A = 0x20,0x22 | PA0
 * Battery = BATT | A = 0x20 | PA1, PA2, PA3
 * nRF24L01 SPI = NRF | A = 0x21,0x22 | PB4, PA4
 * KSZ8851SNL SPI = ETH	| A = 0x21,0x22 | PA5
 * LEDs = LED | D = 0x2A,0x2B | PD4, PD5, PD6
 * LCD_TFT = LCD | B = 0x24,0X25 | PB0, PB1, PB2, PB3, PB4
 * Buttons = BTN | C = 0x26,0x27,0x28 | PC3, PC4, PC4, PC6, PC7
--------------------------------------------------------------------------------------------
 */

/***************************************************************************************************/
#pragma mark - SPI
/* Pins */
#define SPI_DDR		DDRB	// | Offset = 0x24 | Reset = 0x00 | Address = 0x04 |
#define SPI_PORT	PORTB	// | Offset = 0x25 | Reset = 0x00 | Address = 0x05 |
#define SPI_SS		PB4		// | PCINT12 | SS   | OC0B |
#define SPI_MOSI	PB5		// | PCINT13 | MOSI |
#define SPI_MISO	PB6		// | PCINT14 | MISO |
#define SPI_SCK		PB7		// | PCINT15 | SCK  |
/* Methods */
/***************************************************************************************************/
#pragma mark - Charger
/* Pins */
#define CHG_PORT	PORTA	// | Offset = 0x22 | Reset = 0x00 | Address = 0x02 |
#define CHG_PIN		PINA	// | Offset = 0x20 | Reset = N/A  | Address = 0x00 |
#define CHG			PA0		// | PCINT0 | ADC0 |
/* Methods */
#define chg_init()	CHG_PORT |= _BV(CHG);
#define chg_read()	(!(CHG_PIN & _BV(CHG)));
/***************************************************************************************************/
#pragma mark - Battery
/* Pins */
#define BATT_PIN	PINA	// | Offset = 0x20 | Reset = N/A  | Address = 0x00 |
#define BATT_A		PA1		// | PCINT1 | ADC1 |
#define BATT_B		PA2		// | PCINT2 | ADC2 |
#define BATT_C		PA3		// | PCINT3 | ADC3 |
/* Methods */
#define batt_a_read() (BATT_PIN & _BV(BATT_A));
#define batt_b_read() (BATT_PIN & _BV(BATT_B));
#define batt_c_read() (BATT_PIN & _BV(BATT_C));
#define batt_read() ((!!batt_a_read() << 0) | (!!batt_b_read() << 1) | (!!batt_c_read() << 2));
/***************************************************************************************************/
#pragma mark - nRF24L01 SPI
/* Pins */
#define NRF_DDR		DDRA	// | Offset = 0x21 | Reset = 0x00 | Address = 0x01 |
#define NRF_PORT	PORTA	// | Offset = 0x22 | Reset = 0x00 | Address = 0x02 |
#define NRF_CS		SPI_SS	// | PCINT12 | SS   | OC0B |
#define NRF_CE		PA4		// | PCINT4  | ADC4 |
/* Methods */
#define nrf_cs_h() (NRF_PORT != _BV(NRF_CS));
#define nrf_cs_l() (NRF_PORT &= ~_BV(NRF_CS));
#define nrf_ce_h() (NRF_PORT |= _BV(NRF_CE));
#define nrf_ce_l() (NRF_PORT &= ~_BV(NRF_CE));
/***************************************************************************************************/
#pragma mark - KSZ8851SNL SPI
/* Pins */
#define ETH_DDR		DDRA	// | Offset = 0x21 | Reset = 0x00 | Address = 0x01 |
#define ETH_PORT	PORTA	// | Offset = 0x22 | Reset = 0x00 | Address = 0x02 |
#define ETH_CS		PA5		// | PCINT5 | ADC5 |
/* Methods */
#define eth_cs_h() (ETH_PORT |= _BV(ETH_CS));
#define eth_cs_l() (ETH_PORT &= ~_BV(ETH_CS));
/***************************************************************************************************/
#pragma mark - LEDs
/* Pins */
#define LED_DDR		DDRD	// | Offset = 0x2A | Reset = 0x00 | Address = 0x0A |
#define LED_PORT	PORTD	// | Offset = 0x2B | Reset = 0x00 | Address = 0x0B |
#define LED_RED		PD4		// | PCINT28 | OC1B | XCK1 |
#define LED_GREEN	PD5		// | PCINT29 | OC1A |
#define LED_BLUE	PD6		// | PCINT30 | OC2B | ICP1 |
/* Methods */
#define led_init() do {			\
	LED_DDR |= _BV(LED_RED);	\
	LED_DDR |= _BV(LED_GREEN);	\
	LED_DDR |= _BV(LED_BLUE);	\
} while (0);
#define led_toggle_red()	LED_PORT ^= _BV(LED_RED);
#define led_toggle_green()	LED_PORT ^= _BV(LED_GREEN);
#define led_toggle_blue()	LED_PORT ^= _BV(LED_BLUE);
#define led_deinit() do {		\
	LED_DDR &= ~_BV(LED_RED);	\
	LED_DDR &= ~_BV(LED_GREEN);	\
	LED_DDR &= ~_BV(LED_BLUE);	\
} while (0);
/***************************************************************************************************/
#pragma mark - LCD_TFT
/* Pins */
#define LCD_DDR		DDRB	// | Offset = 0x24 | Reset = 0x00 | Address = 0x04 |
#define LCD_PORT	PORTB	// | Offset = 0x25 | Reset = 0x00 | Address = 0x05 |
#define LCD_SCK		PB0		// | PCINT8  | XCK0 | T0   |
#define LCD_AO		PB1		// | PCINT9  | CLKO | T1   |
#define LCD_RST		PB2		// | PCINT10 | AIN0 | INT2 |
#define LCD_CS		PB3		// | PCINT11 | AIN1 | OC0A |
#define LCD_SDA		PB4		// | PCINT12 | SS   | OC0B |
/* Methods */
/***************************************************************************************************/
#pragma mark - Buttons
/* Pins */
#define BTN_PIN			PINC	// | Offset = 0x26 | Reset = N/A  | Address = 0x06 |
#define BTN_DDR			DDRC	// | Offset = 0x27 | Reset = 0x00 | Address = 0x07 |
#define BTN_PORT		PORTC	// | Offset = 0x28 | Reset = 0x00 | Address = 0x08 |
#define BTN_UP			PC3		// | PCINT19 | TMS   |
#define BTN_LEFT		PC4		// | PCINT20 | TDO   |
#define BTN_DOWN		PC5		// | PCINT21 | TDI   |
#define BTN_RIGHT		PC6		// | PCINT22 | TOSC1 |
#define BTN_ENTER		PC7		// | PCINT23 | TOSC2 |
/* Methods */
#define btn_init() do {			\
	BTN_PORT |= _BV(BTN_UP);	\
	BTN_PORT |= _BV(BTN_LEFT);	\
	BTN_PORT |= _BV(BTN_DOWN);	\
	BTN_PORT |= _BV(BTN_RIGHT); \
	BTN_PORT |= _BV(BTN_ENTER); \
} while (0);
#define btn_up_read()		(!(BTN_PIN & _BV(BTN_UP)));
#define btn_left_read()		(!(BTN_PIN & _BV(BTN_LEFT)));
#define btn_down_read()		(!(BTN_PIN & _BV(BTN_DOWN)));
#define btn_right_read()	(!(BTN_PIN & _BV(BTN_RIGHT)));
/***************************************************************************************************/
