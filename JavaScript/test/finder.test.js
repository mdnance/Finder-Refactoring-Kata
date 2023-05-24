const { FT } = require('../src/ft.js');
const { Finder } = require('../src/finder.js');
const { Thing } = require('../src/thing.js');

describe('Finder', () => {
    let sue, greg, sarah, mike;

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

    test('returns Empty Results When Given Empty List', () => {
        const list = [];
        const finder = new Finder(list);

        const result = finder.find(FT.One);
        expect(result.P1).toBeNull();
        expect(result.P2).toBeNull();
    });

    test('returns Empty Results When Given One FT', () => {
        const list = [sue];
        const finder = new Finder(list);

        const result = finder.find(FT.One);
        expect(result.P1).toBeNull();
        expect(result.P2).toBeNull();
    });

    test('returns One Two For Two FTs', () => {
        const list = [sue, greg];
        const finder = new Finder(list);

        const result = finder.find(FT.One);
        expect(result.P1).toBe(sue);
        expect(result.P2).toBe(greg);
    });

    test('returns Two Two For Two FTs', () => {
        const list = [mike, greg];
        const finder = new Finder(list);

        const result = finder.find(FT.Two);
        expect(result.P1).toBe(greg);
        expect(result.P2).toBe(mike);
    });

    test('returns Two Two For Four FTs', () => {
        const list = [sue, sarah, mike, greg];
        const finder = new Finder(list);

        const result = finder.find(FT.Two);
        expect(result.P1).toBe(sue);
        expect(result.P2).toBe(sarah);
    });

    test('returns One Two For Four FTs', () => {
        const list = [sue, sarah, mike, greg];
        const finder = new Finder(list);

        const result = finder.find(FT.One);
        expect(result.P1).toBe(sue);
        expect(result.P2).toBe(greg);
    });
});
