#include "colors.inc"

camera
{ location <25,25,25>
  look_at <0,0,0>
  angle 35
}

light_source {<30,5,5> color White spotlight point_at <0, 5, 5> tightness 0 radius 0 falloff 7}
light_source { <5,30,5> color White spotlight point_at <5, 0, 5> tightness 0 radius 0 falloff 7}                               
light_source { <5,5,30> color White spotlight point_at <5, 5, 0> tightness 0 radius 0 falloff 7}
    
plane{
x,0
pigment {color Red}
}   
    
plane{
y,0
pigment {color Green}
}
   
plane{
z,0
pigment {color Blue}
}   

#declare MyBox =
box{

    <0,0,-2><0.5, 5, 0.5>
}

    #declare E =
    union{ 
    object
    {
        MyBox
        translate <3, 2, 7.5> 
        rotate<0,25,0>
    } 
    object
    {
        MyBox
        translate <6, 3, 3> 
        rotate<0,-25,0>
    }
    object
    {
        MyBox
        translate <3.5, 3, -5.5> 
        rotate<0,-100,0> 
    } 
    } 
    #declare A =
    union{ 
    object
    {
        MyBox
        translate <3, 2, 7.5> 
        rotate<0,25,0>
    } 
    object
    {
        MyBox
        translate <6, 3, 3> 
        rotate<0,-25,0>
    }
    object
    {
        MyBox
        translate <3.5, 3, -5.5> 
        rotate<0,-100,0> 
    } 
    }   
    

difference{ 
    sphere{ 
        <5,5,5>,2
        pigment { color Yellow }
    } 
    box { <3,4,5>,<7,6,11>}
    object
    {  
        A
    }
    object
    {
        A
        rotate<90,0,0>   
        translate <0, 10, 0> 
    } 
    object
    {  
        E
    }
    object
    {
        E
        rotate<90,0,0>   
        translate <0, 10, 0> 
    }

    
} 





 


//box { <6.5,10,5>,<4, 1, 5.5> rotate <30,30,0>}    

    
