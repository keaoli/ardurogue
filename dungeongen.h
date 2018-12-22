#ifndef dungeongen.h
#define dungeongen.h 
#include "bitwiseops.h"



unsigned char tlx;
unsigned char tly;
//top left x and y coords
unsigned char brx;
unsigned char bry;
//bottom right x and y
unsigned char room1x;
unsigned char room1y;
unsigned char room2x;
unsigned char room2y;
//store center co-ords for 2 rooms for the corridoor carving
#define ROOM_NUMBER 10
//amount of rooms per floor, will need tweaking, also used for times to go through array
void coridoor()
{

if (room1x < room2x){
  //dop the positive

  for (; room1x<= room2x; room1x++){
    setMapBit(room1x, room1y);
  }
  if (room1y < room2y){
    // do the negative 
    for (; room1y <= room2y; room1y++){
      setMapBit(room1x, room1y);
    }
  }
  else {
    //do the positive y
    for(;room1y >= room2y; room1y--){
      setMapBit(room1x, room1y);
    }
  }

}
else {
  for (; room1x >= room2x; room1x--){
    setMapBit(room1x, room1y);
  }

 if (room1y < room2y){
    // do the negative 
    for (; room1y <= room2y; room1y++){
      setMapBit(room1x, room1y);
    }
  }
  else {
    //do the positive y
    for(;room1y >= room2y; room1y--){
      setMapBit(room1x, room1y);
    }
  }
}
}
void genDungeon(){
  
  for (unsigned char rooms = 0;rooms < ROOM_NUMBER; rooms++){
  room1x = room2x;
  room1y = room2y;
  tlx = random(2, 53);
  tly = random(2, 53);
  unsigned char storedtlx = tlx;
  unsigned char storedtly = tly;
  brx = tlx + (random(6,12));
  bry = tly + (random(6,12));

    for (; tly < bry; tly++) {
      for (; tlx < brx; tlx++){
        setMapBit(tlx,tly);
       
      }
     tlx = storedtlx;
    }
 tly = storedtly;
 room2x = tlx+((brx- tlx)/2);
 room2y = tly+((bry -tly)/2);
 if(room1x == 0){
  
 }
 else{
  coridoor();

 }
  
}
}














#endif
