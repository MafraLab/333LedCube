
//matriz das camadas em altura
int layer[] = {2,3,4};


void setup()
{
  // layer pins:
  // 2- botlayer
  // 3- middlelayer
  // 4- toplayer
  
  // LED NUMBERING
  //
  //      5------6-------7
  //      |      |       |
  //      8------9-------10
  //      |      |       |
  //      11-----12------13
  //
  
  
    
  // Define all pins as out
  for(int x = 2; x <= 13 ; x++)
  {
    pinMode(x,OUTPUT);
  }
}

void loop()
{
  for(int i = 200; i >= 0; i-=20)
  {
    seq1(i);
    seq2(i);
    seq3(i);
  
  }
  //for(int i = 200; i > 1; i-= 20)
  //{
  //  seq1(i);
  //  seq2(i);
  //}
  
}

//Percurrer todos os leds em sequencia
void seq1(int iSpeed)
{
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  int i = 0;
  int j = 0;
  for(i = 2; i <= 4; i++)
  {
    digitalWrite(i, LOW);
    for(j = 5; j <= 13; j++)
    {
      digitalWrite(j, HIGH);
      delay(iSpeed);
      digitalWrite(j, LOW);
    }
    digitalWrite(i, HIGH);
  }
}

//Percurrer os leds em espiral
void seq2(int iSpeed)
{
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  int seq[] = {5,6,7,10,13,12,11,8};
  
  for( int j = 0; j<3; j++)
  {
    digitalWrite(layer[j],LOW);
    for(int i = 0; i <=8; i++)
    {
      digitalWrite(seq[i], HIGH);
      delay(iSpeed);
      digitalWrite(seq[i], LOW);
    }
    digitalWrite(layer[j],HIGH);
  }
}

void seq3(int iSpeed)
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  
  for(int i = 0; i<=2; i++)
  {
    digitalWrite(5+i, HIGH);
    digitalWrite(8+i, HIGH);
    digitalWrite(11+i, HIGH);
    delay(iSpeed); 
    digitalWrite(5+i, LOW);
    digitalWrite(8+i, LOW);
    digitalWrite(11+i, LOW);
  }
  
  
  for(int i = 0; i<=2; i++)
  {
    digitalWrite(7-i, HIGH);
    digitalWrite(10-i, HIGH);
    digitalWrite(13-i, HIGH);
    delay(iSpeed);
    digitalWrite(7-i, LOW);
    digitalWrite(10-i, LOW);
    digitalWrite(13-i, LOW);
  }
}
