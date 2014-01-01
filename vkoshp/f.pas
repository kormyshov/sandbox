const eps : Double = 0.000000001;

function f(x : Double) : Double;
begin
    f := x*x - sqrt(x);
end;

function bin_search(l, r, c : Double) : Double;
var
    m : Double;
    t : Longint;
begin
    t := 0;
    while (abs(l-r)>eps) and (t<200) do begin
        inc(t);
        m := (l+r) * 0.5;
        if f(m)>c then l := m
        else r := m;
    end;
    bin_search := r;
end;

var
    c, xm : Double;
	t : Longint;
begin
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);

	Read(t);
	while t>0 do begin
		dec(t);
    	Read(c);
    	xm := 0.396850263;

    	if (c<eps) and (c>f(xm)+eps) then Write(bin_search(0.0, xm, c):0:6, ' ');
    	if c>f(xm)-eps then Write(bin_search(1e6, xm, c):0:6);
    	if c<f(xm)-eps then Write('No solution');
		WriteLn;
	end;
end.
