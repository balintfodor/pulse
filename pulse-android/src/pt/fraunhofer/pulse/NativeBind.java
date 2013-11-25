package pt.fraunhofer.pulse;

import org.opencv.core.Mat;
import org.opencv.core.MatOfDouble;
import org.opencv.core.MatOfRect;
import org.opencv.core.Rect;

public class NativeBind
{
	public NativeBind()
	{
		self = _initialize();
	}
	
	public void reset(int width, int height)
	{
		_reset(self, width, height);
	}
	
	public void addFrame(Mat frame)
	{
		_addFrame(self, frame.getNativeObjAddr());
	}
	
	public double calculateBpm()
	{
		return _calculateBpm(self);
	}
	
	public double[] getGraph()
	{
		if (graph == null)
			graph = new MatOfDouble();
		_getGraph(self, graph.getNativeObjAddr());
		return graph.toArray();
	}
	
	@Override
    protected void finalize() throws Throwable
    {
		super.finalize();
		_destroy(self);
        self = 0;
	}
	
	private long self = 0;
	private MatOfDouble graph;
	private static native long _initialize();
    private static native void _reset(long self, int width, int height);
    private static native void _addFrame(long self, long frame);
    private static native void _getGraph(long self, long graph);
    private static native double _calculateBpm(long self);
    private static native void _destroy(long self);

}
