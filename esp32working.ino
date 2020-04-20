

#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "esp32example-5fc3c.firebaseio.com"
#define FIREBASE_AUTH "eC5pQ0XkNYougVexBkB5niXY21x3LqenMMTB2o8A"
#define WIFI_SSID "x"
#define WIFI_PASSWORD "madeinchina"
FirebaseData firebaseData;




// constants won't change. Used here to set a pin number:
const int ledPin =  2;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
    Initialization();
  WiFiConnection();
}



void Initialization(){
  
  Serial.begin(115200); 
 }

void WiFiConnection(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
    if(Firebase.setInt(firebaseData,"/LED_STATUS", 1)){
      Serial.println("ON");
    }
//
//Firebase.setString(firebaseData,"LED_STATUS", "OFF");
}


void loop() {




  

  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
//
//  if (currentMillis - previousMillis >= interval) {
//    // save the last time you blinked the LED
//    previousMillis = currentMillis;
//
//    // if the LED is off turn it on and vice-versa:
//    if (ledState == LOW) {
//      ledState = HIGH;
//      Serial.println("high");
//    } else {
//      ledState = LOW;
//      Serial.println("low");
//    }
//
//    // set the LED with the ledState of the variable:
//    digitalWrite(ledPin, ledState);
//  }


//digitalWrite(ledPin, HIGH); 

 if(Firebase.getInt(firebaseData,"/LED_STATUS")){                  
//Serial.println(fireStatus);
if(firebaseData.intData()==0)
{
  digitalWrite(ledPin, LOW); 
}
if(firebaseData.intData()==1)
{
  digitalWrite(ledPin, HIGH); 
}

//   if (firebaseData.dataType() == "String"){
//      Serial.println(firebaseData.stringData());
//if(firebaseData.stringData()=="OFF")
//
//{
//      Serial.println("Led Turned OFF");
//
//    digitalWrite(ledPin, LOW); 
//}
//
//else if(firebaseData.stringData()=="ON")
//
//{
//      Serial.println("Led Turned ON");
//
//    digitalWrite(ledPin, HIGH); 
//}
//else {
//
//    Serial.println("Wrong Credential! Please send ON/OFF");
//
//  }
//      
//    }
    
    
    
    }

  
}
