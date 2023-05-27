with AUnit;            use AUnit;
with AUnit.Test_Cases; use AUnit.Test_Cases;

package Finder.Tests is

   type Finder_Test is new Test_Cases.Test_Case with null record;

   procedure Register_Tests (T : in out Finder_Test);

   function Name (T : Finder_Test) return Message_String;

   procedure Set_Up_Case (T : in out Finder_Test);

end Finder.Tests;
