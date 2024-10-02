using System;
using System.Collections.Generic;

namespace Algorithm
{
    /*
     * Original kata by K. Scott Allen
     * Forked from some other dude
     * added some additional issues from the clean codes episodes
     */
    public class Find
    {
        private readonly List<Thing> _p; // a list of people

        /// <summary>
        /// 
        /// </summary>
        /// <param name="p">a list of things</param>
        public Find(List<Thing> p)
        {
            _p = p;
        }

        /// <summary>
        /// Warning no one understands this, don't touch it
        /// </summary>
        /// <param name="ft">ft enum</param>
        /// <returns>the oldest or youngest people, depending on the enum</returns>
        public F Finder(FT ft)
        {
            F getAnswer; //the finder answer
            var tr = new List<F>();

            for(var i = 0; i < _p.Count - 1; i++)
            {
                for(var j = i + 1; j < _p.Count; j++)
                {
                    var r = new F();
                    var checkIfYoungest = CheckIfYoungest(i, j);
                    if(checkIfYoungest)
                    {
                        r.P1 = _p[i];
                        r.P2 = _p[j];
                    }
                    else
                    {
                        r.P1 = _p[j];
                        r.P2 = _p[i];
                    }
                    r.D = r.P2.BirthDate - r.P1.BirthDate;
                    tr.Add(r);
                }
            }

            if(tr.Count < 1)
            {
                return new F();
            }

            getAnswer = AnswerResult(ft, tr);

            return getAnswer;
        }

        private bool CheckIfYoungest(int i, int j)
        {
            return _p[i].BirthDate < _p[j].BirthDate;
        }

        // Gets the Answer Result
        private F AnswerResult(FT ft, List<F> tr)
        {
            F answer = tr[0];
            foreach(var result in tr)
            {
                // Console.WriteLine($"current answer:{answer}");
                
                //todo: replace switch with something else
                switch(ft)
                {
                    case FT.One:
                        if(result.D < answer.D)
                        {
                            answer = result;
                            
                            
                        }
                        break;

                    case FT.Two:
                        if(result.D > answer.D)
                        {
                            answer = result;
                        }
                        break;
                }
            }
            return answer;
        } //end of F
    }
}