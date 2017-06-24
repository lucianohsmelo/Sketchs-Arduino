function varargout = Angulo(varargin)
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Angulo_OpeningFcn, ...
                   'gui_OutputFcn',  @Angulo_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

function Angulo_OpeningFcn(hObject, eventdata, handles, varargin)

handles.output = hObject;

guidata(hObject, handles);
clear all;
clc;
global a
a = arduino('COM4');
a.servoAttach(6)

function varargout = Angulo_OutputFcn(hObject, eventdata, handles) 

varargout{1} = handles.output;


function edit1_Callback(hObject, eventdata, handles)
function edit1_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function Enviar_Callback(hObject, eventdata, handles)
global a
ang_s = (get(handles.edit1,'String'))
ang = str2double(ang_s)
if (ang>=13)
a.servoWrite(6,(ang-13))
else
    a.servoWrite(6,0)
end

function slider1_Callback(hObject, eventdata, handles)
global a
ang2 = fix(get(handles.slider1,'Value'))
if (ang2>=13)
a.servoWrite(6,(ang2-13))
else
    a.servoWrite(6,0)
end
function slider1_CreateFcn(hObject, eventdata, handles)
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
