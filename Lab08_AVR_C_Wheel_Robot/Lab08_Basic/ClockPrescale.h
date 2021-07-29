
#ifndef CLOCKPRESCALE_H
#define CLOCKPRESCALE_H
typedef struct ClockPrescale { } ClockPrescale;
void ClockPrescale__change_enable(ClockPrescale* self);
void ClockPrescale__select(ClockPrescale* self, uint16_t prescale);
#endif // CLOCKPRESCALE_H
