// POV-Ray 3.6 / 3.7 Scene File "povhouse3.pov"
// author: Friedrich A. Lohmueller, 2004/Aug-2009/Jan-2011  
// email:  Friedrich.Lohmueller_at_t-online.de
// homepage: http://www.f-lohmueller.de
//------------------------------------------------------------------------
#version 3.6; // 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
//------------------------------------------------------------------------

#declare Camera_1 = camera { 
                             angle 15
                             location  <30.0 , 10.0 ,-40.0>
                             right     x*image_width/image_height
                             look_at   <1.0 , 1.5 , 2.0>
                           }
camera{Camera_1}

//------------------------------------------------------------------------
// sun -------------------------------------------------------------------
light_source{<-1500,2500,-2500> color White}
// sky -------------------------------------------------------------------
sky_sphere{ pigment{ gradient <0,1,0>
                     color_map{ [0   color rgb<1,1,1>         ]//White
                                [0.4 color rgb<0.14,0.14,0.56>]//~Navy
                                [0.6 color rgb<0.14,0.14,0.56>]//~Navy
                                [1.0 color rgb<1,1,1>         ]//White
                              }
                     scale 2 }
           } // end of sky_sphere 
//------------------------------------------------------------------------

//------------------------------ the Axes --------------------------------
//------------------------------------------------------------------------
#macro Axis_( AxisLen, Dark_Texture,Light_Texture) 
 union{
    cylinder { <0,-AxisLen-1,0>,<0,AxisLen,0>,0.05
               texture{checker texture{Dark_Texture } 
                               texture{Light_Texture}
                       translate<0.1,0,0.1>}
             }
    cone{<0,AxisLen,0>,0.2,<0,AxisLen+0.7,0>,0
          texture{Dark_Texture}
         }
     } // end of union                   
#end // of macro "Axis()"
//------------------------------------------------------------------------   
/*
#macro AxisXYZ( AxisLenX, AxisLenY, AxisLenZ, Tex_Dark, Tex_Light)
//--------------------- drawing of 3 Axes --------------------------------
union{
#if (AxisLenX != 0)
 object { Axis_(AxisLenX, Tex_Dark, Tex_Light)   rotate< 0,0,-90>}// x-Axis
 text   { ttf "arial.ttf",  "x",  0.15,  0  texture{Tex_Dark} 
          scale 0.5 translate <AxisLenX+0.05,0.4,-0.10>}
#end // of #if 
#if (AxisLenY != 0)
 object { Axis_(AxisLenY, Tex_Dark, Tex_Light)   rotate< 0,0,  0>}// y-Axis
 text   { ttf "arial.ttf",  "y",  0.15,  0  texture{Tex_Dark}    
           scale 0.5 translate <-0.75,AxisLenY+0.50,-0.10>}
#end // of #if 
#if (AxisLenZ != 0)
 object { Axis_(AxisLenZ, Tex_Dark, Tex_Light)   rotate<90,0,  0>}// z-Axis
 text   { ttf "arial.ttf",  "z",  0.15,  0  texture{Tex_Dark}
               scale 0.5 translate <-0.75,0.2,AxisLenZ+0.10>}
#end // of #if 
} // end of union
#end// of macro "AxisXYZ( ... )"
//------------------------------------------------------------------------


#declare Texture_A_Dark  = texture {
                               pigment{ color rgb<1,0.45,0>}
                               finish { phong 1}
                             }
#declare Texture_A_Light = texture { 
                               pigment{ color rgb<1,1,1>}
                               finish { phong 1}
                             }

object{ AxisXYZ( 4.5, 4.5, 11, Texture_A_Dark, Texture_A_Light) no_shadow}
//-------------------------------------------------- end of coordinate axes
*/

// ground -----------------------------------------------------------------
//---------------------------------<<< settings of squered plane dimensions

    
 
plane { <0,1,0>, 0    // plane with layered textures
        texture{Rust}
        }

 
//------------------------------------------------ end of squered plane XZ

//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------

#declare Hx = 2.00;
#declare Hy = 3.50;
#declare Hz = 4.00;
#declare Roof_Angle = 38; 
#declare Wall_D = 0.20 ;// the thickness of the Wall 

#declare Roof_D = 0.10; // the thickness of the roof
#declare Roof_O = 0.20; // overhang 
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
box { <-Hx,0,0>,< Hx,Hy,Hz>   
      texture {Wall_Texture_1}  
//    no_shadow
    } // end of box --------- 

plane{ <0,-1,0>,0 
      texture {Wall_Texture_1}  
       rotate<0,0,Roof_Angle>
       translate<0,Hy,0>
     }

plane{ <0,-1,0>,0 
      texture {Wall_Texture_1}  
       rotate<0,0,-Roof_Angle>
       translate<0,Hy,0>
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
translate<4, 0, 5>}


//--------------------------------------------------------- end   
#macro Street_0(  Street_Width,  //
                  Street_Length, //
                  Stripes_Width, //
                  Stripes_Len
                ) //-------------------
//-------------------------------------
#ifndef( Stripes_Texture )
#declare Stripes_Texture =
texture{ pigment{ color rgb<1,1,1>*1.1}
         finish { diffuse 0.9 phong 0.5}
       } // end of texture
#end //--------------------------------
#ifndef( Street_Texture )
#declare Street_Texture =
texture{ pigment{ color rgb<1,1,1>*.3}
         normal { bumps 0.5 scale 0.005}
         finish { diffuse 0.9 phong 0.1}
       } // end of texture
#end //--------------------------------
#local D = 0.001;
//-------------------------------------
union{
box{ < -Street_Width/2, 0, 0 >,
     < Street_Width/2, D, Street_Length>
     texture{Street_Texture}
   } // end of box --------------------
 #local Number_of_Stripes =
   int(Street_Length/(2*Stripes_Len));
 #local Nr = 0; //start
 #local EndNr=Number_of_Stripes;//end
 #while (Nr< EndNr)
 box{ <-Stripes_Width/2,   0, 0>,
      < Stripes_Width/2,2*D,Stripes_Len>
      texture{ Stripes_Texture}
      translate<0,0,Nr*2*Stripes_Len>
    } // end of box
 #local Nr = Nr + 1;  // next Nr
 #end // -------- end of loop
} // end of union
#end//-------------------- end of macro
//----------------- end of include file
object{ Street_0 (   6, // Width,
                   100, // Length,
                  0.10, // Stripes_W,
                  1.00, // Stripes_Len
                 ) //-----------------
        translate<3,0,-20>
        rotate<0, 90, 0>}