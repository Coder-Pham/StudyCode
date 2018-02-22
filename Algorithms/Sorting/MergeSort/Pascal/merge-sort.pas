(**
 *  Author: Nhat M. Nguyen
 *  Date: 05-02-18
**)

program merge_sort;


uses crt;


const
  MAXN = 100000;
  INF = 100000;


var
  i, n: longint;
  a: array [0..MAXN] of longint;


procedure merge(var a: array of longint; st: longint; mi: longint; en: longint);

  var
    i, j, k: longint;
    n_left, n_right: longint;
    left: array of longint;
    right: array of longint;

  begin
    n_left := mi - st + 1;
    n_right := en - (mi + 1) + 1;
    
    setlength(left, n_left + 1);
    setlength(right, n_right + 1);

    for i := st to mi do
      left[i - st] := a[i];
    
    for j := mi + 1 to en do
      right[j - mi - 1] := a[j];
    
    left[n_left] := INF;
    right[n_right] := INF;
    i := 0;
    j := 0;

    for k := st to en do
      if left[i] < right[j] then
        begin
          a[k] := left[i];
          i := i + 1;
        end
      else
        begin
          a[k] := right[j];
          j := j + 1;
        end;
  end;


procedure merge_sort(var a: array of longint; st: longint; en: longint);

  var
    mi: longint;

  begin
    if st < en then
      begin
        mi := (st + en) div 2;
        merge_sort(a, st, mi);
        merge_sort(a, mi + 1, en);
        merge(a, st, mi, en);
      end;
  end;


begin
  clrscr;
  readln(n);
  for i := 0 to n - 1 do
    readln(a[i]);
  merge_sort(a, 0, n - 1);
  for i := 0 to n - 1 do
    writeln(a[i]);
end.
