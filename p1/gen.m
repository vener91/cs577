i = 10000
for i = 10000:10000:200000

    A = poissrnd(10000,1,i)
    fid = fopen(strcat('p_', int2str(i)), 'wt');

    for n = 1:i
        fprintf(fid,'%g\n',A(1,n));
    end
     
end

i = 10000
for i = 10000:10000:200000

    A = randi(10000,1, i)
    fid = fopen(strcat('u_', int2str(i)), 'wt');

    for n = 1:i
        fprintf(fid,'%g\n',A(1,n));
    end
end
