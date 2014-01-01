var n, t : Longint;
begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
	Read(t);
	while t>0 do begin
		dec(t);
    	Read(n);
    	if 2*n mod (n-2) = 0 then WriteLn('YES')
    	else WriteLn('NO');
	end;
end.
