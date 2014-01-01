function f(a : Longint) : Longint;
var
    s : Longint;
begin
    s := 0;
    while a>0 do begin
        inc(s, sqr(a mod 10));
        a := a div 10;
    end;
    f := s;
end;

procedure solve;
var
    n, a, i, j : Longint;
    v : array [0..1000] of Longint;
begin
    Read(a, n);
    v[0] := a;
    for i:=1 to n do begin
        a := f(a);
        for j:=0 to i-1 do
            if v[j] = a then begin
                Write(v[j+(n-j) mod (i-j)]);
                exit;
            end;
        v[i] := a;
    end;
    Write(v[n]);
end;

var t : Longint;
begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
	Read(t);
	while t>0 do begin
		dec(t);
		solve;
		WriteLn;
	end;
end.
