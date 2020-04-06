
#declare Hx = 2.00 ;
#declare Hy = 3.50;
#declare Hz = 4.00;
#declare Roof_Angle = 38; 
#declare Wall_D = 0.20;// the thickness of the Wall 

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
box { <Hx,Hy,Hz>,<-Hx,0,0> 
      texture {Wall_Texture_1}  
//    no_shadow
    } // end of box ---------  
    
              box { <Hx-5,Hy,Hz-clock*40>,<Hx+5,0,5> 
      texture {Wall_Texture_1}  
//    no_shadow
    } // end of box --------- 
    
plane{ <0,-1 -clock,0>,0 
      texture {Wall_Texture_1}  
       rotate<0,0,Roof_Angle>
       translate<0,Hy,0>
     }

plane{ <0,-1 -clock,0>,0 
      texture {Wall_Texture_1}  
       rotate<0,0,-Roof_Angle>
       translate<0,Hy,0>
     }
 // inside caved out

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
      rotate<0,0 + clock*1400, Roof_Angle>
      translate<0,Hy - clock*50, 0 -clock*10>
     }
box { < -Roof_L, 0.00, -Roof_O>,< Roof_D/2, Roof_D, Hz+Roof_O>  
      texture {Roof_Texture translate<-0.05,0,0>}  
      rotate<0,0 + clock*1400, Roof_Angle>
      translate<0,Hy - clock*50, 0 - clock*17> scale<-1,1,1>
     }               
//------------------------------------------------- end of Roof

//----------------------------------------------- Windows
object{ Door   translate Window_Positon_1f rotate<0 + clock*1100,0,0>}
object{ Window translate Window_Positon_2f}
object{ Window rotate<0 - clock*1700,180,0> translate Window_Positon_1b}
object{ Window rotate<0 - clock*1700,180,0> translate Window_Positon_2b}
object{ Window rotate<0 - clock*1700,-90,0> translate Window_Positon_1r}
object{ Window rotate<0 - clock*1700,-90,0> translate Window_Positon_2r}
object{ Window rotate<0 - clock*1700, 90,0> translate Window_Positon_1l}
object{ Window rotate<0 - clock*1700, 90,0> translate Window_Positon_2l}     
