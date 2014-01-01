var n, m, t : Longint;
begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
	Read(t);
	while t>0 do begin
		dec(t);
    	Read(n, m);
    	WriteLn(n*m div (m-1), ' ', n div (m-1));
	end;
end.
