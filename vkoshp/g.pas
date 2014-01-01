const
  dx : array [0..1,0..5] of Longint=(( 0, 1, -1, 1, 0, 1),(-1, 0, -1, 1, -1, 0)); 
  dy : array [0..1,0..5] of Longint=((-1, -1, 0, 0, 1, 1),(-1, -1, 0, 0,  1, 1)); 

var
    n, m, i, j, y, x, lq : Longint;
    mm : array [1..1000,1..1000] of Longint;
    qx, qy : array [1..1000000] of Longint;
    s : AnsiString;

procedure solve;
begin
    ReadLn(n, m);
    ReadLn(y, x);
    for i:=1 to n do begin
        ReadLn(s);
        for j:=1 to m do
            mm[i,j] := ord(s[j])-49;
    end;

    qx[1] := x;
    qy[1] := y;
    lq := 1;
    j := 1;
    while j<=lq do begin
        y := qy[j];
        x := qx[j];
        if (x=1) or (y=1) or (x=m) or (y=n) then begin
            Write(mm[y,x]+1);
            exit;
        end;
        for i:=0 to 5 do
            if mm[y+dy[y and 1, i],x+dx[y and 1, i]] = 0 then begin
                mm[y+dy[y and 1, i],x+dx[y and 1, i]] := mm[y, x] + 1;
                inc(lq);
                qy[lq] := y+dy[y and 1, i];
                qx[lq] := x+dx[y and 1, i];
            end;
		inc(j);
    end;

    Write('No solution');
end;

var t : Longint;
begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
	ReadLn(t);
	while t>0 do begin
		dec(t);
		solve;
		WriteLn;
	end;
end.
