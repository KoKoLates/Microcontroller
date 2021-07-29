
#ifndef ADCONVERTER_H
#define ADCONVERTER_H
typedef struct ADConverter
{

}ADConverter;
void ADConverter__init(ADConverter* self);
void ADConverter__start(ADConverter* self);
uint16_t ADConverter__read(ADConverter* self);
#endif //ADCONVERTER_H

