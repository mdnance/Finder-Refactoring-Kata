with AUnit.Assertions; use AUnit.Assertions;
with AUnit.Test_Cases; use AUnit.Test_Cases;
with GNAT.Source_Info;

package body Finder.Tests is

   Sue   : Thing;
   Greg  : Thing;
   Sarah : Thing;
   Mike  : Thing;

   procedure Set_Up_Case (T : in out Finder_Test) is
   begin
       Sue := Make_Thing("Sue", 1950, 1, 1);
       Greg := Make_Thing("Greg", 1952, 6, 1);
       Sarah := Make_Thing("Sarah", 1982, 1, 1);
       Mike := Make_Thing("Mike", 1979, 1, 1);      
   end Set_Up_Case;

   -- helper Assert for Things
   procedure Assert
     (Actual, Expected : Thing; --
      Message          : String;
      Source           : String  := GNAT.Source_Info.File;
      Line             : Natural := GNAT.Source_Info.Line) is
   begin
      Assert (Name_String.To_String (Actual.Name),
             Name_String.To_String (Expected.Name), Message, Source, Line);
   end Assert;

   procedure Test_Returns_Empty_Results_When_Given_Empty_List (T : in out Test_Cases.Test_Case'Class)
   is
      List   : P_Vectors.Vector;
      Result : F;
   begin
      Result := Finder.Find (List, One);

      Assert ("", Name_String.To_String (Result.P1.Name), "first");
      Assert ("", Name_String.To_String (Result.P2.Name), "second");
   end Test_Returns_Empty_Results_When_Given_Empty_List;

   procedure Test_Returns_Empty_Results_When_Given_One_FT (T : in out Test_Cases.Test_Case'Class)
   is
      List   : P_Vectors.Vector;
      Result : F;
   begin
      List.Append (Sue);

      Result := Finder.Find (List, One);

      Assert ("", Name_String.To_String (Result.P1.Name), "first");
      Assert ("", Name_String.To_String (Result.P2.Name), "second");
   end Test_Returns_Empty_Results_When_Given_One_FT;

   procedure Test_Returns_One_Two_For_Two_FTs (T : in out Test_Cases.Test_Case'Class)
   is
      List   : P_Vectors.Vector;
      Result : F;
   begin
      List.Append (Sue);
      List.Append (Greg);

      Result := Finder.Find (List, One);

      Assert (Result.P1, Sue, "first");
      Assert (Result.P2, Greg, "second");
   end Test_Returns_One_Two_For_Two_FTs;

   procedure Test_Returns_Two_Two_For_Two_FTs (T : in out Test_Cases.Test_Case'Class)
   is
      List   : P_Vectors.Vector;
      Result : F;
   begin
      List.Append (Mike);
      List.Append (Greg);

      Result := Finder.Find (List, Two);

      Assert (Result.P1, Greg, "first");
      Assert (Result.P2, Mike, "second");
   end Test_Returns_Two_Two_For_Two_FTs;

   procedure Test_Returns_Two_Two_For_Four_FTs (T : in out Test_Cases.Test_Case'Class)
   is
      List   : P_Vectors.Vector;
      Result : F;
   begin
      List.Append (Sue);
      List.Append (Sarah);
      List.Append (Mike);
      List.Append (Greg);

      Result := Finder.Find (List, Two);

      Assert (Result.P1, Sue, "first");
      Assert (Result.P2, Sarah, "second");
   end Test_Returns_Two_Two_For_Four_FTs;

   procedure Test_Returns_One_Two_For_Four_FTs (T : in out Test_Cases.Test_Case'Class)
   is
      List   : P_Vectors.Vector;
      Result : F;
   begin
      List.Append (Sue);
      List.Append (Sarah);
      List.Append (Mike);
      List.Append (Greg);

      Result := Finder.Find (List, One);

      Assert (Result.P1, Sue, "first");
      Assert (Result.P2, Greg, "second");
   end Test_Returns_One_Two_For_Four_FTs;

   procedure Register_Tests (T : in out Finder_Test) is
      use AUnit.Test_Cases.Registration;
   begin
      Register_Routine (T, Test_Returns_Empty_Results_When_Given_Empty_List'Access, "Returns_Empty_Results_When_Given_Empty_List");
      Register_Routine (T, Test_Returns_Empty_Results_When_Given_One_FT'Access, "Returns_Empty_Results_When_Given_One_FT");
      Register_Routine (T, Test_Returns_One_Two_For_Two_FTs'Access, "Returns_One_Two_For_Two_FTs");
      Register_Routine (T, Test_Returns_Two_Two_For_Two_FTs'Access, "Returns_Two_Two_For_Two_FTs");
      Register_Routine (T, Test_Returns_Two_Two_For_Four_FTs'Access, "Returns_Two_Two_For_Four_FTs");
      Register_Routine (T, Test_Returns_One_Two_For_Four_FTs'Access, "Returns_One_Two_For_Four_FTs");
   end Register_Tests;

   function Name (T : Finder_Test) return Message_String is
   begin
      return Format ("Finder Tests");
   end Name;

end Finder.Tests;
