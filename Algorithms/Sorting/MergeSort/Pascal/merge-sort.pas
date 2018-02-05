(**
 *  Author: Nhat M. Nguyen
 *  Date: 05-02-18
**)

program merge_sort;


uses crt;


const
  INF = 10000;
  MAXN = 1000;


var
  i: integer;
  a: array [1..MAXN] of integer = (3, 7, 1, 5, 0, 9, 2, 8, 4, 6);


procedure merge(a: array of integer, start_index: integer, mid_index: integer, end_index: integer);
  var
    i, j: integer;
    n_left, n_right: integer;
    left, right: array of integer;

  begin
    n_left := mid_index - start_index + 1;
    n_right := end_index - mid_index;

    setlength(left, n_left + 1);
    setlength(right, n_right + 1);

    for i := start_index to mid_index do
      left[i - start_index] := a[i];

    for j := mid_index + 1 to end_index do
      right[i - mid_index - 1] := a[i];

    left[n_left] := INF;
    right[n_right] := INF;

    i := 0;
    j := 0;
    for k := start_index to end_index do
      if left[i] <= right[j] then
        begin
          a[k] := left[i]
          i := i + 1;
        end;
      else
        begin
          a[k] := right[j];
          j := j + 1;
        end;
  end;


procedure merge_sort(a: array of integer, start_index: integer, end_index: integer);
  var
    mid_index: integer;

  begin
    mid_index := (start_index + end_index) div 2;

    merge_sort(a, start_index, mid_index);
    merge_sort(a, mid_index + 1, end_index);

    merge(a, start_index, mid_index, end_index);
  end;


begin
  clrscr;
  merge_sort(a, 0, 10 - 1);
  for i := 0 to 9 do
    write(a[i], ' ');
  readln
end.
