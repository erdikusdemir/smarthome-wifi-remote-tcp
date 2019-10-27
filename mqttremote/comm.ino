void tcpread() {
char buffer1[10] = {};
char buffer2[10] = {};
int k=0;
boolean fp=1;
//memset(mesaj, 0, sizeof(mesaj));
client.read(mesaj,100);
Serial.println((const char*)mesaj);
//Serial.println(sizeof(mesaj));

for (int i = 0; i <= 100; i++)
{
if(mesaj[i]==123 || mesaj[i]==44) // ASCII 123: { 44: , 125: } 58: :
{ //mesajın bası bulundu şimdi ilk ayracı ve mesajın sonunu bulalım.
 for (int j = i+1; j <= 100; j++)
  {
  if(mesaj[j]==125 || mesaj[j]==44)
  {
    i=j;

if(buffer1[0]==105&&buffer1[1]==100)syscursor=atoi(buffer2);//id
if(buffer1[0]==110&&buffer1[1]==97)strcpy(menu0[syscursor],buffer2);//name
if(buffer1[0]==115&&buffer1[1]==116)state[syscursor]=atoi(buffer2);//state
if(buffer1[0]==118&&buffer1[5]==48)value0[syscursor]=atoi(buffer2);//value0
if(buffer1[0]==118&&buffer1[5]==49)value1[syscursor]=atoi(buffer2);//value1
if(buffer1[0]==116&&buffer1[1]==121)type[syscursor]=atoi(buffer2);//type
if(buffer1[0]==109&&buffer1[1]==105)mid=atoi(buffer2);//mid
 
k=0;
fp=1;
memset(buffer1, 0, sizeof(buffer1));
memset(buffer2, 0, sizeof(buffer2));

    }
      else
      {
        if(mesaj[j]==58){fp=0;k=0;j++;}
       if(mesaj[j]!=34){
        if(fp)buffer1[k] = mesaj[j];
        else buffer2[k]=mesaj[j];
      k++;
       }//if char 34
      }//else
  
  }//j loop

  
}//mesajın bası

}//i loop

   Serial.println(menu0[syscursor]);
   Serial.println(value0[syscursor]);

if(seqcounter>=mid-1){initseq=0;seqcounter=0;lastreflesh=1;screenhandler();}
if(initseq)seqcounter++;

//memset(mesaj, 0, sizeof(mesaj));
//client.stop();
}//end of callback




//void reconnect() {
//if (client.connect(mqtt_clientid, mqtt_username, mqtt_password)) {
//client.subscribe(inTopic);
//} else {
//Serial.print("failed, rc=");
//Serial.print(client.state());
//Serial.println(" try again in 5 seconds");
//display.setCursor(0,0);//cursor
//display.println("MQTT connection failed.");
//display.display();
//display.clearDisplay();
//delay(5000);
//}
//Serial.println("connected");
//Serial.println(millis()-basla);
//}//end of reconnect

void initdata(){//init data from HA -call is inside void reconnect()
//if (client.connected()){
String payload = "{\"id\": 99}";
payload.toCharArray(data, (payload.length() + 1));
//client.publish(outTopic , data);
client.println(data);
initseq= 1;

}//end of init

//void callback(char* topic, byte* payload, unsigned int length) {
//Serial.println((const char*)payload);
//JsonObject& root = JSONBuffer.parseObject((const char*)payload); //Parse message
//syscursor = root["id"];
//state[syscursor] = root["state"];
//value0[syscursor] = root["value0"];
//if(initseq){
//menu0[syscursor] =root["name"];
////Serial.println(menu0[syscursor]);
//type[syscursor] = root["type"];
//
//if(type[syscursor]==2) value1[syscursor]=root["value1"];
//mid= root["mid"];
//mid--;
//if(seqcounter>=mid){initseq=0;seqcounter=0;lastreflesh=1;screenhandler();}
//seqcounter++;
//}//end initseq
//if(type[syscursor]==2) value1[syscursor]=root["value1"];
//Serial.println(seqcounter);
//Serial.println(mid);
//}//end of callback

void outputhandler() {
  String payload;
if(type[dispcursor]==2)payload = "{\"id\": "+ String(dispcursor) +", \"state\": " + String(state[dispcursor]) +", \"value1\": " + String(value1[dispcursor])+ "}";
else payload = "{\"id\": "+ String(dispcursor) +", \"state\": " + String(state[dispcursor]) +", \"value0\": " + String(value0[dispcursor])+ "}";
payload.toCharArray(data, (payload.length() + 1));
//client.publish(outTopic , data);
client.println(data);
outputchanged=0;
}//end of outputhandler
