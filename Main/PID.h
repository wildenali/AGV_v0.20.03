/*working variables*/
unsigned long lastTime;
int Input, OutputPID, Setpoint = 0;
double errSum, lastErr;
//int kp = 1;
//int ki = 0;
//int kd = 100;

const int numReadingsPID = 10;
int readingsPID[numReadingsPID];      // the readings from the analog input
int readIndexPID = 0;              // the index of the current reading
int totalPID = 0;                  // the running total
int PID_result = 0;                // the average

void Compute(int nilaiInput)
{
   Input = nilaiInput;
   unsigned long now = millis();
   double timeChange = (double)(now - lastTime);
  
   /*Compute all the working error variables*/
   double error = Setpoint + Input;
   errSum += (error * timeChange);
   double dErr = (error - lastErr) / timeChange;
  
   /*Compute PID Output*/
   OutputPID = GgainP * error + GgainI * errSum + GgainD * dErr;
   
   /*Remember some variables for next time*/
   lastErr = error;
   lastTime = now;
}

void PID_filter(){
  totalPID = totalPID - readingsPID[readIndexPID];
  readingsPID[readIndexPID] = OutputPID;
  totalPID = totalPID + readingsPID[readIndexPID];
  readIndexPID = readIndexPID + 1;
  if (readIndexPID >= numReadingsPID) {
    readIndexPID = 0;
  }
  PID_result = totalPID / numReadingsPID;
}

void PID_compute(int nilaiInputCompute){
  Compute(nilaiInputCompute);
  PID_filter();
}

