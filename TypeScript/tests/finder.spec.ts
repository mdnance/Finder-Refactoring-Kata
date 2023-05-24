import Finder from '../src/finder';
import { FT } from '../src/ft';
import Thing from '../src/thing';

describe('Finder', () => {
    let sue: Thing;
    let greg: Thing;
    let sarah: Thing;
    let mike: Thing;

    beforeEach(() => {
        sue = new Thing();
        sue.name = "Sue";
        sue.birthDate = new Date(50, 0, 1);

        greg = new Thing();
        greg.name = "Greg";
        greg.birthDate = new Date(52, 5, 1);

        sarah = new Thing();
        sarah.name = "Sarah";
        sarah.birthDate = new Date(82, 0, 1);

        mike = new Thing();
        mike.name = "Mike";
        mike.birthDate = new Date(79, 0, 1);
    });

    it('returns Empty Results When Given Empty List', () => {
        const list: Thing[] = [];
        const finder = new Finder(list);

        const result = finder.find(FT.One);

        expect(result.P1).toBeNull();
        expect(result.P2).toBeNull();
    });

    it('returns Empty Results When Given One FT', () => {
        const list: Thing[] = [sue];
        const finder = new Finder(list);

        const result = finder.find(FT.One);

        expect(result.P1).toBeNull();
        expect(result.P2).toBeNull();
    });

    it('returns One Two For Two FTs', () => {
        const list: Thing[] = [sue, greg];
        const finder = new Finder(list);

        const result = finder.find(FT.One);

        expect(result.P1).toBe(sue);
        expect(result.P2).toBe(greg);
    });

    it('returns Two Two For Two FTs', () => {
        const list: Thing[] = [mike, greg];
        const finder = new Finder(list);

        const result = finder.find(FT.Two);

        expect(result.P1).toBe(greg);
        expect(result.P2).toBe(mike);
    });

    it('returns Two Two For Four FTs', () => {
        const list: Thing[] = [sue, sarah, mike, greg];
        const finder = new Finder(list);

        const result = finder.find(FT.Two);

        expect(result.P1).toBe(sue);
        expect(result.P2).toBe(sarah);
    });

    it('returns One Two For Four FTs', () => {
        const list: Thing[] = [sue, sarah, mike, greg];
        const finder = new Finder(list);

        const result = finder.find(FT.One);

        expect(result.P1).toBe(sue);
        expect(result.P2).toBe(greg);
    });
});
