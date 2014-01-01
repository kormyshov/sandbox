uses math;
var
    t, n, mn, mx, one : Int64;
    i : Longint;
begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
	Read(t);
	while t>0 do begin
		dec(t);
    	Read(n);
    	one := 1;
    	mn := one shl 62;
		mx := 0;
    	for i:=0 to 62 do
    	    if (n and (one shl i))>0 then begin
    	        mn := min(mn, one shl i);
    	        mx := max(mx, one shl i);
    	    end;
    	WriteLn(mn, ' ', mx);
	end;
end.
