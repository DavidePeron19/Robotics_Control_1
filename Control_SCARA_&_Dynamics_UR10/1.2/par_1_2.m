%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Homework
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% controller par
Kp = 3000*eye(4);
Kd = 4000*eye(4);

% 3000 3000
% 2000 4000
% 6000 10000
% 12000 60000

%% set initial conditions

q_0 = [0;0;0;0];
% q_0 = [pi/2;-pi/2;0;0];
q_dot_0 = [0;0;0;0];


%% Set point to point par

q_target = [pi/2; pi/3; 0.1; -pi/4];
[b_filt, a_filt] = butter(1, 10,'s');

%% sin trj par

% sin par
omega_sin = 0.5*[1; 1; 1; 1];
a_sin = [pi/2; pi/2; 0.2; pi/2];




%% 1 sim
Kp = 3000*eye(4);
Kd = 3000*eye(4);

omega_sin = 0.5*[1; 1; 1; 1];
%% 2 sim
Kp = 3000*eye(4);
Kd = 5000*eye(4);

omega_sin = 3*[1; 1; 1; 1];
%% 3 sim
Kp = 3000*eye(4);
Kd = 10000*eye(4);

omega_sin = 6*[1; 1; 1; 1];
%% 4 sim
Kp = 3000*eye(4);
Kd = 30000*eye(4);

omega_sin = 10*[1; 1; 1; 1];