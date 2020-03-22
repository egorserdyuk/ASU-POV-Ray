

#default{ finish{ ambient 0.1 diffuse 0.9 }}

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

#declare Camera_ = camera {angle 80     
                            location  <0.0 , 1.0 ,-3.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.2 , 0.0>}
camera{Camera_}
light_source{<-1500,2500,-2500> color White}   
light_source{ <-3,2,-1>
              color White
 }

fog { fog_type   2
      distance   50
      color      White  
      fog_offset 0.1
      fog_alt    1.5
      turbulence 1.8
    }

plane { <0,1,0>, 0 
        texture{ pigment{ color 0 }
                 finish { phong 0.1 }
               } 
      } 

                                                                                             
#declare Tire_tex  =
 texture{ pigment{ color rgb<1,1,1>*0.05}
          finish { phong 0.1 } }
#declare Rim_tex =    
 texture{ Polished_Chrome        
          finish { phong 1.0 }}                        
#declare Spoke_tex =   
 texture{ Polished_Chrome        
          finish { phong 1.0 }}                         

#declare Number_of_spokes = 12;
#declare W = 360/Number_of_spokes; 

union{ 
torus{0.9,0.20 scale <1,1,1> rotate<90,0,0>
         texture{Rim_tex}} 
torus{1.0,0.25 scale <1,1,1> rotate<90,0,0>
         texture{Tire_tex}}


union{ 
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 0*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 1*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 2*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 3*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 4*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 5*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 6*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 7*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 8*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0, 9*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0,10*W>}
  cylinder {<0,0,0>,<1,0, 0>,0.05 rotate<0,0,11*W>}
  texture{Spoke_tex}
 } 


translate<0,1.25,0> 
rotate<0, 0, 0>
}