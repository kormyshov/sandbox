var
    ii, num, n, i, t : Longint;
    f, e, d, c : array [1..100] of String;
    m : array [1..100] of Longint;

function cmp(a, b : Longint) : Boolean;
begin
    if length(c[a]) > length(c[b]) then cmp := true
    else if length(c[a]) < length(c[b]) then cmp := false
    else if c[a] > c[b] then cmp := true
    else if c[a] < c[b] then cmp := false
    else cmp := (f[a] > f[b]);
end;

begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);

	ReadLn(num);
	for ii:=1 to num do begin
		WriteLn('Case ',ii,':');

    	ReadLn(n);

    	for i:=1 to n do begin
    	    ReadLn(f[i]);
    	    ReadLn(e[i]);
    	    ReadLn(c[i]);
    	    ReadLn(d[i]);
    	    m[i] := i;
    	end;

    	i:=1;
    	while i<n do
    	    if cmp(m[i], m[i+1]) then begin
    	        t := m[i];
    	        m[i] := m[i+1];
    	        m[i+1] := t;
    	        if i>1 then dec(i);
    	    end else inc(i);

    	for i:=1 to n do
    	    WriteLn(c[m[i]],' ',f[m[i]],' ',e[m[i]],' ',d[m[i]]);
	end;
end.
