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