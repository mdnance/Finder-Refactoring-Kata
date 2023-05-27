with Ada.Containers.Vectors;
with Ada.Calendar;

package body Finder is
    use Ada.Calendar; -- for < in line 18 and 25

    package Tr_Vectors is new Ada.Containers.Vectors (Index_Type => Natural, Element_Type => F);

    function Find (P : P_Vectors.Vector; FT : FT_Type) return F is
        Tr     : Tr_Vectors.Vector;
        Answer : F;
    begin
        for I in P.First_Index .. P.Last_Index - 1 loop
            for J in I + 1 .. P.Last_Index loop
                declare
                    R : F;
                begin
                    if P (I).BirthDate < P (J).BirthDate then
                        R.P1 := P (I);
                        R.P2 := P (J);
                    else
                        R.P1 := P (J);
                        R.P2 := P (I);
                    end if;
                    R.D := Integer (R.P2.BirthDate - R.P1.BirthDate);
                    Tr.Append (R);
                end;
            end loop;
        end loop;

        if Tr.Last_Index = Tr_Vectors.No_Index then
            Answer :=
               (P1 =>
                   Thing'
                      (Name      => Name_String.To_Bounded_String (""),
                       BirthDate => Ada.Calendar.Clock),
                P2 =>
                   Thing'
                      (Name      => Name_String.To_Bounded_String (""),
                       BirthDate => Ada.Calendar.Clock),
                D  => 0);
        else
            Answer := Tr (1);
            for Result of Tr loop
                case FT is
                    when One =>
                        if Result.D < Answer.D then
                            Answer := Result;
                        end if;
                    when Two =>
                        if Result.D > Answer.D then
                            Answer := Result;
                        end if;
                end case;
            end loop;
        end if;

        return Answer;
    end Find;

end Finder;
