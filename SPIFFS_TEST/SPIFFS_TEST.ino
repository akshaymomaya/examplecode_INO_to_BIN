/* Copyright: Mission Critical: Youtube.

   ! Disclaimer of Warranty !  

   This Work is provided "as is". Any express or implied warranties, including but not limited to,the implied warranties of merchantability and fitness for a particular purpose are disclaimed.
   In no event shall the Mission Critical be liable for any direct, indirect, incidental, special, exemplary or consequential damages (including, but not limited to, procurement of substitute goods or services, loss of use, data or profits,
   or business interruption) however caused and on any theory of liability, whether in contract, strict liability, or tort (including negligence or otherwise) arising in any way out of the use of this Work, 
   even if advised of the possibility of such damage.
   The User of this Work agrees to hold harmless and indemnify the Mission Critical, its agents and employees from every claim or liability (whether in tort or in contract), including attorneys' fees,
   court costs, and expenses, arising in direct consequence of Recipient's use of the item, including but not limited to, claims or liabilities made for injury to or death of personnel of User or third parties,
   damage to or destruction of property of User or third parties, infringement or other violations of intellectual property or technical data rights.
   Nothing in this Work is intended to constitute an endorsement, explicit or implied, by Mission Critical of any particular manufacturer's product or service.

   Firmware Usecase:

   1. to read the Data in "test.txt" file of SPIFFs Drive of ESP32 and display it in Serial Monitor.

   Written by Akshay Momaya :: Date: 16/10/2022 (DD/MM/YYYY)

   VERSION Details:
   ESP32 Version: v1.0.4 (Check in board manager).
   esptool.py v2.6
*/


/*Libraries*/
#include "SPIFFS.h"

void setup() 
{
   Serial.begin(115200); /*Begin the Serial Monitor at 115200 buad rate*/
   
   if(!SPIFFS.begin(true)){Serial.println("An Error has occurred while mounting SPIFFS"); return;}  /*SPIFFS Initialisation*/
   
    File file2 = SPIFFS.open("/test1.txt"); /* File Declaration*/
 
    if(!file2)  /* Error Coding */
    {
        Serial.println("Failed to open file for reading");
        return;
    }
 
    Serial.println("File Content:");
 
    while(file2.available())
    {
      Serial.write(file2.read()); /*Read File and Display Output at Serial Terminal*/
    }
    file2.close();
}
 
void loop() {}
