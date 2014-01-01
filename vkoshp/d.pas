uses math;
var
    t, n, f, m, a, i : Longint;
    x : Double;

begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);

	Read(t);
	while t>0 do begin
		dec(t);
    	Read(n, f, m);
    	x := (100.0-f)/100*n;

    	for i:=1 to m do begin
    	    Read(a);
    	    inc(n, a);
    	end;

    	WriteLn(n,' ',floor((n-x)/n*100+0.500000001));
	end;
end.
