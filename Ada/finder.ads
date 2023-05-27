with Ada.Calendar; use Ada.Calendar;
with Ada.Containers.Vectors;
with Ada.Strings.Bounded;

package Finder is

   package Name_String is new Ada.Strings.Bounded.Generic_Bounded_Length (Max => 20);

   type Thing is record
      Name      : Name_String.Bounded_String;
      BirthDate : Time;
   end record;

   function Make_Thing(Name : String; Year : Year_Number; Month : Month_Number; Day : Day_Number) return Thing;

   package P_Vectors is new Ada.Containers.Vectors (Index_Type => Natural, Element_Type => Thing);

   type FT_Type is (One, Two);

   type F is record
      P1 : Thing;
      P2 : Thing;
      D  : Integer;
   end record;

   function Find (P : P_Vectors.Vector; FT : FT_Type) return F;

end Finder;
