package body Finder is

    function Make_Thing(Name : String; Year : Year_Number; Month : Month_Number; Day : Day_Number) return Thing is
    begin
        return Thing' (Name      => Name_String.To_Bounded_String (Name),
                       BirthDate => Time_Of (Year, Month, Day));
    end Make_Thing;

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
            Answer := (P1 => Make_Thing("", 1901, 1, 1),
                       P2 => Make_Thing("", 1901, 1, 1),
                       D  => 0);
        else
            Answer := Tr (Tr.First_Index);
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
