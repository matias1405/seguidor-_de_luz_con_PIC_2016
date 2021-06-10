# include <16f877A.h>
# device adc=8
# use delay(clock=4M)

int s_analogica(int i);
void motores(float derecha, float izquierda);

void main()
{
   float luz_derecha, luz_izquierda, i;
   setup_adc_ports(ALL_ANALOG);
    setup_adc(ADC_CLOCK_INTERNAL);

    while(true)
    {
       i=0;
      luz_derecha=s_analogica(i);
      i=1;
      luz_izquierda=s_analogica(i);
      motores(luz_derecha,luz_izquierda);
      }
}

int s_analogica(int i){
   float luz;
    set_adc_channel(i);
   delay_us(40); //para dar estabilidad
   luz=(float)read_adc();
   return luz;
}

void motores(float derecha, float izquierda){
   float adelante;
    if(derecha<200 || izquierda<200){
       adelante=derecha-izquierda;
       adelante=abs(adelante);
         if(adelante<100){
            output_high(PIN_B0);
            output_high(PIN_B1);
            }
         else{
            if(derecha<izquierda){
               output_high(PIN_B1);
               output_low(PIN_B0);
               }
            else{
               output_low(PIN_B1);
               output_high(PIN_B0);
               }
            }
         } 
else{
      output_low(PIN_B0);
      output_low(PIN_B1);
   }
}

