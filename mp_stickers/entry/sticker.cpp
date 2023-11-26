#include "Image.h"
#include "StickerSheet.h"
using namespace std;

int main() 
{
  Image alma,sticker_uno,sticker_dos,sticker_tres;
  alma.readFromFile("../data/alma.png");
  sticker_uno.readFromFile("../data/i.png");
  sticker_dos.readFromFile("../data/penguin.png");
  
  
  StickerSheet output(alma, 3);
  output.addSticker(sticker_uno, 1150, 150);
  output.addSticker(sticker_dos, 400, 50);


  Image final_look = output.render();
  final_look.writeToFile("myImage.png");
  
  return 0;
}
