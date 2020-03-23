#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"


#declare Camera = camera {/*ultra_wide_angle*/ angle 80   // diagonal view
                            location  < 12.00, 2.50,-7.00>
                            right     x*image_width/image_height
                            look_at   <2.00, 0.00+1, 0.00>}
camera{Camera}
//------------------------------------------------------------------------------------------------------------
// sun ---------------------------------------------------------------------
light_source{< 1500,2500,-2500> color White}

// sky -------------------------------------------------------------- 
plane{<0,1,0>,1 hollow  
       texture{ pigment{ bozo turbulence 0.92
                         color_map { [0.00 rgb <0.20, 0.20, 1.0>*0.9]
                                     [0.50 rgb <0.20, 0.20, 1.0>*0.9]
                                     [0.70 rgb <1,1,1>]
                                     [0.85 rgb <0.25,0.25,0.25>]
                                     [1.0 rgb <0.5,0.5,0.5>]}
                        scale<1,1,1.5>*2.5  translate< 0,0,0>
                       }
                finish {ambient 1 diffuse 0} }      
       scale 10000}
// fog on the ground -------------------------------------------------
fog { fog_type   2
      distance   150
      color      White  
      fog_offset 0.1
      fog_alt    2.5
      turbulence 1.8
    }

// ground ------------------------------------------------------------
plane { <0,1,0>, 0 
        texture{ pigment{ color rgb<0.35,0.65,0.0>*0.72 }
	         normal { bumps 0.75 scale 0.015 }
                 finish { phong 0.1 }
               } // end of texture
      } // end of plane
//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------// 
#include "Street_10.inc"  // street with center stripes with continuous border lines
//-------------------------------------------------------------------------------------// 
object{ Street_10( 6,     // Street_Widthm, // 
                   1000 , // Street_Length, //
                   0.10,  // Stripes_Width, // 
                   1.00,  // Stripes_Length                                  
                 ) //------------------------------------------------------------------//
        scale <1,1,1>*1
        rotate<0,90,0> 
        translate<-500.00,0.00,0.00>}
//-------------------------------------------------------------------------------------// 
//---------------------------------------------------------------------------------------
object{ Street_10( 6,     // Street_Widthm, // 
                   1000 , // Street_Length, //
                   0.10,  // Stripes_Width, // 
                   1.00,  // Stripes_Length                                  
                 ) //------------------------------------------------------------------//
        scale <1,1,1>*1
        rotate<0,90,0> 
        translate<-500.00,0.00,6.00>}
//-------------------------------------------------------------------------------------// 
//---------------------------------------------------------------------------------------


 
//---------------------------------------------------------
#declare Truck_Texture1 =   
   texture{ pigment{ color rgb<1,0.9,0.4>*1.1}
            finish { diffuse 0.9 phong 1}
          }
//----------------------------------------
#include "Truck0.inc"
//---------------------------------------------------------
//---------------------------------------------------------
#declare Truck_Texture2 =  
   texture{ pigment{ color rgb<1,1,1>*1.1}
            finish { diffuse 0.9 phong 1}
          }
//----------------------------------------
//---------------------------------------------------------
object{ Truck0(  0, // Front wheel angle: ~  +/-60
                 0, // Trailer angle:   ~ +/-110
                Truck_Texture2 
              ) //-----------------------------------------
rotate<0,0,0> translate<3.00,0,-1.5>}
//---------------------------------------------------------
//----------------------------------------------------- end             

#declare Hx = 2.00;
#declare Hy = 3.50;
#declare Hz = 13.00;
#declare Roof_Angle = 40; 
#declare Wall_D = 0.20 ;// the thickness of the Wall 

#declare Roof_D = 0.10; // the thickness of the roof
#declare Roof_O = 0.10; // overhang 
#declare Roof_L = Hx+0.80;// try it !!! 
// ---------------------------------------------------- Window_Positions
// front positions 
#declare Window_Positon_1f = <-Hx/2,0,Wall_D/3>;
#declare Window_Positon_2f = < Hx/2,0,Wall_D/3>;
// backside positions
#declare Window_Positon_1b = <-Hx/2,0,Hz-Wall_D/3>;
#declare Window_Positon_2b = < Hx/2,0,Hz-Wall_D/3>;
// right side positions
#declare Window_Positon_1r = < Hx-Wall_D/3,0,3*Hz/4>;
#declare Window_Positon_2r = < Hx-Wall_D/3,0,  Hz/4>;
// left side positions
#declare Window_Positon_1l = <-Hx+Wall_D/3,0,3*Hz/4>;
#declare Window_Positon_2l = <-Hx+Wall_D/3,0,  Hz/4>;
// ------------------------------------------------- end of Window_Positions

#declare Wall_Texture_1 = 
      texture { pigment{ color White*1.1}
                normal { bumps 0.5 scale 0.005} 
                
              } // end of texture
#declare Wall_Texture_2 = 
      texture { pigment{ color White*1.1}
               
              } // end of texture

#declare Roof_Texture = 
 // layered texture!!!
      texture { pigment{ color Scarlet*1.3}
                normal { gradient z scallop_wave scale<1,1,0.15>} 
               
              } // end of texture
 
//--------------------------------------------------------

//--------------------- Window -----------
#declare Window_Texture_1 = 
texture{pigment{ color White*1.3}
       }
#declare Window_Texture_2 = 
texture{pigment{ color White*1.2}
        }
//-----------------------------------------
#declare Window = 
union{
 difference{
  box{<-0.50,0.80,-0.02>,< 0.50,1.80,0.02>}
  box{<-0.45,0.85,-0.03>,<-0.03,1.27,0.03>}
  box{< 0.03,0.85,-0.03>,< 0.45,1.27,0.03>}
  box{<-0.45,1.33,-0.03>,<-0.03,1.75,0.03>}
  box{< 0.03,1.33,-0.03>,< 0.45,1.75,0.03>}
  texture{Window_Texture_1}
  } // ---end of difference 
 box{<-0.49,0.81,0.0>,< 0.49,1.79,0.001>
 texture{T_Glass3}}  // no interior!!!
 } // ---end of union
#declare Window_Hole =   //symmetric!!!
  box{<-0.50,0.80,-0.50>,< 0.50,1.80,0.50>
      texture{Window_Texture_2}}

//--------- end of window definition -------

#declare Door = 
union{
 difference{
  box{<-0.50,0.01,-0.02>,< 0.50,1.80,0.02>}
  box{<-0.45,0.85,-0.03>,<-0.03,1.27,0.03>}
  box{< 0.03,0.85,-0.03>,< 0.45,1.27,0.03>}
  box{<-0.45,1.33,-0.03>,<-0.03,1.75,0.03>}
  box{< 0.03,1.33,-0.03>,< 0.45,1.75,0.03>}
  texture{Window_Texture_1}
  } // ---end of difference 
 box{<-0.49,0.81,0.0>,< 0.49,1.79,0.001>
 texture{T_Glass3}}  // no interior!!!
 } // ---end of union
#declare Door_Hole =   //symmetric!!!
  box{<-0.50,0.01,-0.50>,< 0.50,1.80,0.50>
      texture{Window_Texture_2}}

//--------- end of window definition -------



// the walls caved out ----------------------- the Walls
difference{
box { <-Hx,0,20>,< Hx,Hy,Hz>   
      texture {Wall_Texture_1}  
//    no_shadow
    } // end of box --------- 

plane{ <0,-1,0>,0 
      texture {Wall_Texture_1}  
       rotate<0,0,Roof_Angle>
       translate<0,Hy,13>
     }

plane{ <0,-1,0>,0 
      texture {Wall_Texture_1}  
       rotate<0,0,-Roof_Angle>
       translate<0,Hy,13>
     }
 // inside caved out
box { <-Hx+Wall_D,0.10,Wall_D>,
      <Hx-Wall_D,Hy,Hz-Wall_D>  
      texture {Wall_Texture_2}  
     }
// subtract window holes
object{ Door_Hole   translate Window_Positon_1f}
object{ Window_Hole translate Window_Positon_2f}

object{ Window_Hole translate Window_Positon_1r}
object{ Window_Hole translate Window_Positon_2r}

object{ Window_Hole translate Window_Positon_1l}
object{ Window_Hole translate Window_Positon_2l}

object{ Window_Hole translate Window_Positon_1b}
object{ Window_Hole translate Window_Positon_2b}
 

}// end of intersection  ------------------------- end of Walls


// the Roof 
box { < -Roof_L, 0.00, -Roof_O>,< Roof_D/2, Roof_D, Hz+Roof_O>  
      texture {Roof_Texture translate<-0.05,0,0>}  
      rotate<0,0, Roof_Angle>
      translate<0,Hy,0>
     }
box { < -Roof_L, 0.00, -Roof_O>,< Roof_D/2, Roof_D, Hz+Roof_O>  
      texture {Roof_Texture translate<-0.05,0,0>}  
      rotate<0,0, Roof_Angle>
      translate<0,Hy,0> scale<-1,1,1>
     }
//------------------------------------------------- end of Roof

//----------------------------------------------- Windows
object{ Door   translate Window_Positon_1f}
object{ Window translate Window_Positon_2f}
object{ Window rotate<0,180,0> translate Window_Positon_1b}
object{ Window rotate<0,180,0> translate Window_Positon_2b}
object{ Window rotate<0,-90,0> translate Window_Positon_1r}
object{ Window rotate<0,-90,0> translate Window_Positon_2r}
object{ Window rotate<0, 90,0> translate Window_Positon_1l}
object{ Window rotate<0, 90,0> translate Window_Positon_2l} 

#declare w6=0;
#declare w5=30;
#declare w4=-70;
#declare w3=100;
#declare w2=-150;

#declare ww6=w6;
#declare ww5=w5;
#declare ww4=w4;
#declare ww3=w3;
#declare ww2=w2;

#declare i=0;

#macro tribe()

#declare i=i+1;

#if (i<6)
    tribe()
    tribe()
#end

cylinder{<0,0,0>,<0,1,0>,0.2,1.0 pigment{color rgb<0.99-i*0.05,0.35+i*0.08,0.35>}

         #if(i>5)
            scale <0.5,1.5,0.5>
            rotate <60,w6,0>
            translate y*1
         #end 
         #if(i>4)
            scale <0.8,1.0,0.8>
            rotate <60,w5,0>
            translate y*1
         #end            
         #if(i>3)
             scale <0.8,0.8,0.8>
             rotate <50,w4,0>
             translate y*1
         #end             
         #if(i>2)
             scale <0.7,0.7,0.7>
             rotate <40,w3,0>
             translate y*1
         #end             
         #if(i>1)
             scale <0.6,0.6,0.6>
             rotate <50,w2,0>
             translate y*1
         #end
         normal{granite 0.3 scallop_wave  scale 0.6}
         }
#if(i=6)#declare w6=w6+120;#end
#if(i=5)#declare w5=w5+120;#end
#if(i=4)#declare w4=w4+120;#end
#if(i=3)#declare w3=w3+120;#end
#if(i=2)#declare w2=w2+180;#end

#declare i=i-1;
#end


//////////////////////////////
#macro leaves()

#declare i=i+1;

#if (i<6)
    leaves()
    leaves()
#end

#if(i=6)sphere{<0,0,0>,0.8 pigment{bozo scale 0.1 color_map{[0.25 color rgb<0.5,0.6,0.4>][0.35 color rgbt 1]}}
         scale<3,1,3>scale 0.7 translate y*1
         #if(i>5)
            scale <0.5,1.5,0.5>
            rotate <60,ww6,0>
            translate y*1
         #end 
         #if(i>4)
            scale <0.8,1.0,0.8>
            rotate <60,ww5,0>
            translate y*1
         #end            
         #if(i>3)
             scale <0.8,0.8,0.8>
             rotate <50,ww4,0>
             translate y*1
         #end             
         #if(i>2)
             scale <0.7,0.7,0.7>
             rotate <40,ww3,0>
             translate y*1
         #end             
         #if(i>1)
             scale <0.6,0.6,0.6>
             rotate <50,ww2,0>
             translate y*1
         #end
         normal{spotted 0.5  scale 0.02}
         }
#end
         
#if(i=6)#declare ww6=ww6+120;leaves()#end
#if(i=5)#declare ww5=ww5+120;#end
#if(i=4)#declare ww4=ww4+120;#end
#if(i=3)#declare ww3=ww3+120;#end
#if(i=2)#declare ww2=ww2+180;#end

#declare i=i-1;
#end


#declare tree=
union
{
  blob
  {
    threshold 0.3
    tribe()
  }
  #declare i=0;
  leaves()
  scale 1.5
}
////////////////////////////////
////////////////////////////////

object{tree
translate<6, 0, 10>}