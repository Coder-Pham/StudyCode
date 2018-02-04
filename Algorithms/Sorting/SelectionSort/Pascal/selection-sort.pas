program selection_sort;

uses crt;

var
    i: integer;
    j: integer;
    max_index: integer;
    tmp: integer;
    a: array [0..9] of integer = (4, 7, 1, 9, 2, 8, 6, 3, 0, 5);

begin
    clrscr;
    for i := 9 downto 1 do
        begin
            max_index := i;
            for j := i - 1 downto 0 do
                if a[j] > a[max_index] then
                    max_index := j;
            tmp := a[max_index];
            a[max_index] := a[i];
            a[i] := tmp;
        end;

    for i := 0 to 9 do
        write(a[i], ' ');

    readln;
end.
