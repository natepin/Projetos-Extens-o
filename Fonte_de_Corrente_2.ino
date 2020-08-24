//portas usadas pelo arduino
#define portatensao A0
#define res1 2
#define res2 3
#define res3 4
#define res4 5
#define res5 6
#define res6 7
#define res7 8
#define res8 9

//funçoes
void lercorrente();
void ligaresistores(); //funçao para ligar os resistores mediante a tensao
void zeroseuns();
int buscabinaria(); //realiza a busca para qual combinação de vetores será usada

float resistenciaequivalentes[256] = {0.000000, 0.047345, 0.049218, 0.049594, 0.050159, 0.050980, 0.051653, 0.051858, 0.052266, 0.052690, 0.053159, 0.053597, 0.054114, 0.054257, 0.054569, 0.055021, 0.055253, 0.056011, 0.056252, 0.056732, 0.057073, 0.057232, 0.057691, 0.057822, 0.058341, 0.058744, 0.058916, 0.059455, 0.059992, 0.060269, 0.060497, 0.061066, 0.061212, 0.061655, 0.061924, 0.062246, 0.062439, 0.063138, 0.063181, 0.063337, 0.063961, 0.064218, 0.064445, 0.064535, 0.065168, 0.065525, 0.065829, 0.065855, 0.066514, 0.066561, 0.067202, 0.067251, 0.067428, 0.067966, 0.068066, 0.068293, 0.068685, 0.068788, 0.069507, 0.069536, 0.069773, 0.069879, 0.070289, 0.070537, 0.071040, 0.071094, 0.071428, 0.071483, 0.072260, 0.072699, 0.072814, 0.073073, 0.073105, 0.073918, 0.074037, 0.074498, 0.074770, 0.074776, 0.074891, 0.075556, 0.075648, 0.075779, 0.075841, 0.076674, 0.076737, 0.076969, 0.077633, 0.077670, 0.078097, 0.078610, 0.078920, 0.079551, 0.079689, 0.080038, 0.080442, 0.080546, 0.081045, 0.081450, 0.081710, 0.081782, 0.082046, 0.082985, 0.083095, 0.083329, 0.083913, 0.084266, 0.084412, 0.085257, 0.085374, 0.085542, 0.086684, 0.086693, 0.087061, 0.087157, 0.087742, 0.087866, 0.088916, 0.089043, 0.089654, 0.090150, 0.090557, 0.091530, 0.091665, 0.092312, 0.092839, 0.093176, 0.093613, 0.094401, 0.094544, 0.094837, 0.094982, 0.095793, 0.096254, 0.096617, 0.097194, 0.097922, 0.098076, 0.099219, 0.099712, 0.100326, 0.101102, 0.101267, 0.102664, 0.102833, 0.103649, 0.103785, 0.104313, 0.104326, 0.106030, 0.106289, 0.106471, 0.107819, 0.108058, 0.108644, 0.109639, 0.110046, 0.110241, 0.111943, 0.112437, 0.112573, 0.113070, 0.113860, 0.114861, 0.115074, 0.115909, 0.116650, 0.116946, 0.118337, 0.119041, 0.120236, 0.121264, 0.121353, 0.123012, 0.123610, 0.123773, 0.126008, 0.126178, 0.126545, 0.126803, 0.128720, 0.129061, 0.129081, 0.129899, 0.131323, 0.131699, 0.134361, 0.134470, 0.135358, 0.135757, 0.137314, 0.140210, 0.140421, 0.141731, 0.141946, 0.144000, 0.145044, 0.146822, 0.147292, 0.148358, 0.148491, 0.151884, 0.152387, 0.154351, 0.155522, 0.156049, 0.158962, 0.159955, 0.160229, 0.163995, 0.164283, 0.168447, 0.168618, 0.170646, 0.173113, 0.177743, 0.178432, 0.180193, 0.182251, 0.187513, 0.188897, 0.189279, 0.195849, 0.197776, 0.201097, 0.203989, 0.208996, 0.210716, 0.217782, 0.220795, 0.224589, 0.232444, 0.241073, 0.244000, 0.251198, 0.261306, 0.264000, 0.274069, 0.277782, 0.286146, 0.299020, 0.306022, 0.330790, 0.339380, 0.357642, 0.371629, 0.378488, 0.405864, 0.432922, 0.466703, 0.502843, 0.544000, 0.567629, 0.664000, 0.844000, 1.044000, 1.244000} ;
int valoresdecimais[256] = {0, 255, 127, 191, 223, 239, 63, 247, 95, 159, 111, 175, 119, 207, 183, 31, 215, 47, 231, 79, 55, 143, 251, 87, 151, 253, 103, 167, 15, 199, 123, 187, 23, 125, 219, 189, 39, 221, 235, 71, 135, 59, 237, 243, 91, 61, 155, 245, 93, 107, 157, 171, 7, 109, 115, 203, 173, 179, 27, 117, 205, 211, 181, 254, 29, 43, 213, 227, 75, 45, 51, 139, 229, 77, 83, 53, 141, 126, 147, 249, 190, 85, 99, 149, 163, 222, 11, 101, 195, 165, 238, 13, 19, 197, 121, 62, 246, 185, 21, 35, 94, 217, 158, 67, 37, 110, 131, 233, 174, 69, 133, 118, 206, 57, 241, 182, 89, 30, 214, 153, 3, 105, 46, 230, 169, 5, 78, 113, 54, 201, 142, 177, 250, 86, 25, 209, 150, 252, 102, 41, 225, 166, 73, 14, 198, 49, 137, 122, 186, 81, 22, 124, 145, 218, 188, 97, 38, 161, 220, 234, 70, 9, 193, 134, 58, 236, 242, 17, 90, 60, 154, 244, 33, 92, 106, 156, 170, 65, 6, 108, 129, 114, 202, 172, 178, 26, 116, 204, 210, 180, 28, 42, 212, 226, 1, 74, 44, 50, 138, 228, 76, 82, 52, 140, 146, 248, 84, 98, 148, 162, 10, 100, 194, 164, 12, 18, 196, 120, 184, 20, 34, 216, 66, 36, 130, 232, 68, 132, 56, 240, 88, 152, 2, 104, 168, 4, 112, 200, 176, 24, 208, 40, 224, 72, 48, 136, 80, 144, 96, 160, 8, 192, 16, 32, 64, 128};
int valorbinario[8] = {0,0,0,0,0,0,0,0};

#define    c_sens    A1
float   volt, c_value;


void setup() {
  Serial.begin(9600);
  DDRD = B11111100; //portas 2 até 7 como saída 
  DDRB = B00000011; //portas 8 e 9 como saída
  DDRC = B111110; //porta 0 analog como entrada
  pinMode(c_sens, INPUT);

}
void loop() {
  int lerporta = analogRead(portatensao);
  float leituratensao = ((float)lerporta * 5.0) / 1023.0;
  float correntedesejada = 20.0;
  float resdesejada = leituratensao/correntedesejada;
  Serial.println(lerporta);
 // Serial.println(leituratensao);
  //resdesejada = 0.2195;
  //Serial.println(resdesejada);

  lercorrente(correntedesejada);

  int linhaparabinario = buscabinaria(resistenciaequivalentes, resdesejada);
  int decimal = valoresdecimais[linhaparabinario];
  //Serial.println(linhaparabinario);
 // Serial.println(decimal);
  zeroseuns(decimal, valorbinario);
  ligaresistores(valorbinario);

  
}

void lercorrente(float correntedesejada) {
  int h=1;
  while (h==1) {
  //calcula tensão
  volt = (5.0 / 1023.0)*analogRead(c_sens);// Read the voltage from sensor

  //normaliza para sensor ACS758 050B
  volt = volt - 2.5 + 0.007 ;

  //calcula corrente (ACS758 050B varia 40mV / A)
  c_value = volt/0.04;
  c_value = c_value -1.3795;


  //Imprime dados via serial
  Serial.print("V: ");
  Serial.print(volt,3);
  Serial.print("V   |   I: ");
  Serial.print(c_value,1); 
  Serial.println("A");
  if(c_value > (correntedesejada + 0.2) || c_value < (correntedesejada - 0.2)) {
    h=0;
  }
  }
}

int buscabinaria(float resistenceq[256], float resdesejada) {
    int menor = 0;
    int maior = 255;
    int meio, aux1, aux2;
    float comparador1, comparador2, comparador3;
    //int condicional;

    while (maior >= menor) {
        meio = (maior + menor)/2;
        if (resdesejada == resistenceq[meio]) {
            return meio;
        }
        else {
            if (resdesejada > resistenceq[meio]){
                menor = meio + 1;
            }
            else {
                maior = meio - 1;
            }
        }
    }
    if (meio == maior || meio == menor) {
        aux1 = meio + 1;
        aux2 = meio - 1;
        if(aux1 > 256) {
            comparador1= resistenceq[meio] - resdesejada;
            comparador2= resistenceq[aux2] - resdesejada;
            //condicional = (comparador1 < comparador2) ? meio : aux2;
            //return condicional;
            if(fabs(comparador1) < fabs(comparador2)) {
                return meio;
            }
            else {
                return aux2;
            }
        }
        else {
            if(aux2 < 0) {
                comparador1 = resistenceq[meio] - resdesejada;
                comparador2 = resistenceq[aux1] - resdesejada;
                //condicional = (fabs(comparador1) < fabs(comparador2)) ? meio : aux2;
                //return condicional;
                if(fabs(comparador1) < fabs(comparador2)) {
                    return meio;
                }
                else {
                    return aux1;
                }
            }
            else {
                comparador1= resistenceq[meio] - resdesejada;
                comparador2= resistenceq[aux1] - resdesejada;
                comparador3= resistenceq[aux2] - resdesejada;
                //condicional = (comparador1 < comparador2) ? meio : aux2;
                //return condicional;
                if( (fabs(comparador1) < fabs(comparador2)) && (fabs(comparador1) < fabs(comparador3)) ) {
                    return meio;
                }
                else {
                    if( (fabs(comparador2) < fabs(comparador1)) && (fabs(comparador2) < fabs(comparador3)) ) {
                        return aux1;
                    }
                    else {
                        return aux2;
                    }
                }
            }
        }
    }
    return 0;
}    


void zeroseuns(int valor, int binario[8]) {
  int kek = 0;
  int quociente;
  int resto;
  for(int i=0; i<8; i++){
    quociente = valor/2;
    resto = valor%2;
    kek = 7-i;
    binario[kek] = resto;
    valor = quociente;
  }
}

void ligaresistores(int resisbinario[8]) {   
  digitalWrite(res8, resisbinario[7]);
  digitalWrite(res7, resisbinario[6]);
  digitalWrite(res6, resisbinario[5]);
  digitalWrite(res5, resisbinario[4]);
  digitalWrite(res4, resisbinario[3]);
  digitalWrite(res3, resisbinario[2]);
  digitalWrite(res2, resisbinario[1]);
  digitalWrite(res1, resisbinario[0]);        
}
