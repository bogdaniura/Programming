classdef app1 < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure               matlab.ui.Figure
        GreyScaleCheckBox      matlab.ui.control.CheckBox
        MotionBlurSlider       matlab.ui.control.Slider
        MotionBlurSliderLabel  matlab.ui.control.Label
        BlurSlider             matlab.ui.control.Slider
        BlurSliderLabel        matlab.ui.control.Label
        IncarcaoimagineButton  matlab.ui.control.Button
        UIAxes                 matlab.ui.control.UIAxes
    end

    
    properties (Access = private)
        OriginalImage 
        ProcessedImage 
    end
    
    methods (Access = private)
        
    function applyFilters(app)
        img = app.OriginalImage;
        if isempty(img)
            return;
        end
        
        normalBlurAmount = app.BlurSlider.Value;
        if normalBlurAmount > 0
            h = fspecial('gaussian', [15 15], normalBlurAmount);
            img = imfilter(img, h);
        end

        motionBlurAmount = app.MotionBlurSlider.Value;
        if motionBlurAmount > 0
            len = motionBlurAmount;
            theta = 0; % Angle of motion blur
            psf = fspecial('motion', len, theta);
            img = imfilter(img, psf, 'replicate');
        end

        if app.GreyScaleCheckBox.Value
            img = rgb2gray(img);
        end
        
        app.ProcessedImage = img;
        imshow(app.ProcessedImage, 'Parent', app.UIAxes);
    end            
end
    

    % Callbacks that handle component events
    methods (Access = private)

        % Button pushed function: IncarcaoimagineButton
        function IncarcaoimagineButtonPushed(app, event)
            [file, path] = uigetfile({'*.jpg;*.png;*.bmp', 'Images (*.jpg, *.png, *.bmp)'});
            if isequal(file, 0)
                return;
            end
            imgPath = fullfile(path, file);
            app.OriginalImage = imread(imgPath);
            imshow(app.OriginalImage, 'Parent', app.UIAxes);
            app.ProcessedImage = app.OriginalImage;
        end

        % Value changed function: BlurSlider
        function BlurSliderValueChanged(app, event)
            app.applyFilters();
        end

        % Value changed function: MotionBlurSlider
        function MotionBlurSliderValueChanged(app, event)
            app.applyFilters();
        end

        % Value changed function: GreyScaleCheckBox
        function GreyScaleCheckBoxValueChanged(app, event)
            app.applyFilters();
        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure and hide until all components are created
            app.UIFigure = uifigure('Visible', 'off');
            app.UIFigure.Position = [100 100 640 480];
            app.UIFigure.Name = 'MATLAB App';

            % Create UIAxes
            app.UIAxes = uiaxes(app.UIFigure);
            title(app.UIAxes, 'Imagine')
            app.UIAxes.XTick = [];
            app.UIAxes.YTick = [];
            app.UIAxes.Position = [171 180 300 257];

            % Create IncarcaoimagineButton
            app.IncarcaoimagineButton = uibutton(app.UIFigure, 'push');
            app.IncarcaoimagineButton.ButtonPushedFcn = createCallbackFcn(app, @IncarcaoimagineButtonPushed, true);
            app.IncarcaoimagineButton.Tag = 'LoadImageButton';
            app.IncarcaoimagineButton.Position = [480 436 141 23];
            app.IncarcaoimagineButton.Text = 'Incarca o imagine';

            % Create BlurSliderLabel
            app.BlurSliderLabel = uilabel(app.UIFigure);
            app.BlurSliderLabel.HorizontalAlignment = 'right';
            app.BlurSliderLabel.Position = [49 84 27 22];
            app.BlurSliderLabel.Text = 'Blur';

            % Create BlurSlider
            app.BlurSlider = uislider(app.UIFigure);
            app.BlurSlider.ValueChangedFcn = createCallbackFcn(app, @BlurSliderValueChanged, true);
            app.BlurSlider.Tag = 'NormalBlurSlider';
            app.BlurSlider.Position = [97 93 212 3];

            % Create MotionBlurSliderLabel
            app.MotionBlurSliderLabel = uilabel(app.UIFigure);
            app.MotionBlurSliderLabel.HorizontalAlignment = 'right';
            app.MotionBlurSliderLabel.Position = [9 151 67 22];
            app.MotionBlurSliderLabel.Text = 'Motion Blur';

            % Create MotionBlurSlider
            app.MotionBlurSlider = uislider(app.UIFigure);
            app.MotionBlurSlider.ValueChangedFcn = createCallbackFcn(app, @MotionBlurSliderValueChanged, true);
            app.MotionBlurSlider.Tag = 'MotionBlurSlider';
            app.MotionBlurSlider.Position = [97 160 212 3];

            % Create GreyScaleCheckBox
            app.GreyScaleCheckBox = uicheckbox(app.UIFigure);
            app.GreyScaleCheckBox.ValueChangedFcn = createCallbackFcn(app, @GreyScaleCheckBoxValueChanged, true);
            app.GreyScaleCheckBox.Tag = 'GrayscaleCheckbox';
            app.GreyScaleCheckBox.Text = 'Grey Scale';
            app.GreyScaleCheckBox.Position = [391 105 80 22];

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = app1

            % Create UIFigure and components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end